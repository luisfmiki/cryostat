#include "experiment.h"
#include "cryostat.h"
#include "spectrometer.h"
#include "experiment.h"

#include <QState>
#include <QFinalState>
#include <QFile>
#include <QTextStream>
#include <QDebug>

ExperimentController::ExperimentController(
    CryostatController* cryo,
    SpectrometerController* spec,
    QObject* parent)
    : QObject(parent),
    m_cryo(cryo),
    m_spec(spec)
{
    setupStateMachine();
}

void ExperimentController::setOutputFile(const QString& filePath)
{
    m_outputFilePath = filePath;
}

void ExperimentController::setupStateMachine()
{
    QState* idle = new QState();
    QState* cooling = new QState();
    QState* settingTemp = new QState();
    QState* acquiring = new QState();
    QFinalState* finished = new QFinalState();

    m_machine.addState(idle);
    m_machine.addState(cooling);
    m_machine.addState(settingTemp);
    m_machine.addState(acquiring);
    m_machine.addState(finished);

    m_machine.setInitialState(cooling);

    idle->addTransition(this, &ExperimentController::startRequested, settingTemp);
    cooling->addTransition(this, &ExperimentController::coolingFinished, idle);
    settingTemp->addTransition(this, &ExperimentController::temperatureReached, acquiring);
    acquiring->addTransition(this, &ExperimentController::internalSpectrumReady, settingTemp);

    // Cooling
    connect(cooling, &QState::entered, [this]() {
        m_spec->coolTo(-60);
    });

    connect(m_spec, &SpectrometerController::coolingReady,
            this, &ExperimentController::coolingFinished);

    // Set temperature
    connect(settingTemp, &QState::entered, [this]() {
        m_cryo->setTemperature(m_currentTemp);
    });

    connect(m_cryo, &CryostatController::temperatureStabilized,
            this, &ExperimentController::temperatureReached);

    // Acquire spectrum
    connect(acquiring, &QState::entered, [this]() {
        m_spec->acquireSpectrum();
    });

    connect(m_spec, &SpectrometerController::spectrumReady,
            this, &ExperimentController::internalSpectrumReady);

    // When spectrum arrives
    connect(this, &ExperimentController::internalSpectrumReady,
            [this](QVector<double> wl,
                   QVector<double> intensity)
            {
                storeSpectrum(m_currentTemp, wl, intensity);
                advanceTemperature();
            });

    connect(&m_machine, &QStateMachine::finished,
            this, &ExperimentController::experimentFinished);

    m_machine.start();
}

void ExperimentController::start(double startK,
                                 double endK,
                                 double stepK)
{
    m_start = startK;
    m_end = endK;
    m_step = stepK;
    m_currentTemp = startK;

    m_wavelengthAxis.clear();
    m_temperatures.clear();
    m_intensityMatrix.clear();

    emit startRequested();
}

void ExperimentController::pause()
{
    m_machine.stop();
}

void ExperimentController::resume()
{
    m_machine.start();
}

void ExperimentController::abort()
{
    m_machine.stop();
    emit experimentAborted();
}

void ExperimentController::storeSpectrum(
    double temperature,
    const QVector<double>& wavelength,
    const QVector<double>& intensity)
{
    if (m_wavelengthAxis.isEmpty())
        m_wavelengthAxis = wavelength;

    m_temperatures.append(temperature);
    m_intensityMatrix.append(intensity);
}

void ExperimentController::advanceTemperature()
{
    m_currentTemp += m_step;

    if ((m_step > 0 && m_currentTemp > m_end) ||
        (m_step < 0 && m_currentTemp < m_end))
    {
        writeCsvFile();
        m_machine.stop();
        emit experimentFinished();
    }
}

void ExperimentController::writeCsvFile()
{
    if (m_outputFilePath.isEmpty())
        return;

    QFile file(m_outputFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);

    int nPixels = m_wavelengthAxis.size();
    int nTemps  = m_temperatures.size();

    for (int pixel = 0; pixel < nPixels; ++pixel)
    {
        // First column = wavelength
        out << m_wavelengthAxis[pixel];

        // Then each temperature column
        for (int t = 0; t < nTemps; ++t)
            out << "," << m_intensityMatrix[t][pixel];

        out << "\n";
    }

    file.close();
}
