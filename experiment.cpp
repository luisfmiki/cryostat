#include "experiment.h"
#include "cryostat.h"
#include "spectrometer.h"
#include "experiment.h"
#include "mainwindow.h"

#include <QState>
#include <QFinalState>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>

ExperimentController::ExperimentController(
    CryostatController* cryo,
    SpectrometerController* spec,
    MainWindow* main_window,
    QObject* parent)
    : QObject(parent),
    m_cryo(cryo),
    m_spec(spec),
    m_main_window(main_window)
{
    connect(this, &ExperimentController::updateCCDTemp, m_main_window, &MainWindow::ccd_temp_update);
    connect(&m_ccd_temp_pool, &QTimer::timeout, this, [this](){
        int ccd_temperature;
        emit m_spec->checkCCDTemp(&ccd_temperature);
        if (ccd_temperature < -55 && !cooling_finished) {
            cooling_finished = true;
            emit coolingFinished();
            m_main_window->enableExpInputs(true);
        }
    });
    connect(&m_cryo_temp_pool, &QTimer::timeout, this, [this](){
        m_current_temp = m_cryo->getTemperature();
        if(m_cryo->isTemperatureStable(m_target, m_current_temp)) {
            m_stable_cnt++;
            if(m_stable_cnt>2) {
                m_stable_cnt = 0;
                m_cryo_temp_pool.stop();
                emit tempSetted();
            }
        }
        else {
            m_stable_cnt = 0;
        }
    });
    connect(&m_cryo_temp_pool_a, &QTimer::timeout, this, [this](){
       emit m_main_window->showCryoTemp(m_cryo->getTemperature());
    });
    m_cryo_temp_pool_a.start(1000);
    connect(m_main_window, &MainWindow::changeSlit, m_spec, &SpectrometerController::changeSlit);
    connect(m_main_window, &MainWindow::changeGrating, m_spec, &SpectrometerController::changeGrating);
    m_main_window->receiveSpecParams(m_spec->currentParameters());
    connect(m_main_window, &MainWindow::changeWavelength, m_spec, &SpectrometerController::changeWavelength);
    connect(m_main_window, &MainWindow::startSweep, this, &ExperimentController::start);
    connect(m_spec, &SpectrometerController::spectrumReady, this, &ExperimentController::receiveSpec);
    connect(m_main_window, &MainWindow::enableLivePlot, m_spec, &SpectrometerController::livePlot);
    connect(m_spec, &SpectrometerController::liveSpecReady, m_main_window, &MainWindow::livePlot);
    connect(m_main_window, &MainWindow::pauseSweep, this, &ExperimentController::pause);
    connect(m_main_window, &MainWindow::abortSweep, this, &ExperimentController::abort);
    connect(m_main_window, &MainWindow::saveData, this, &ExperimentController::save);
    connect(m_spec, &SpectrometerController::gratingChanged, m_main_window, &MainWindow::changedGrating);
    connect(m_spec, &SpectrometerController::changedWavelength, m_main_window, &MainWindow::changedWavelength);
    connect(m_spec, &SpectrometerController::ccdTempReadReady, m_main_window, &MainWindow::ccd_temp_update);
    connect(m_main_window, &MainWindow::closeShutter, m_spec, &SpectrometerController::closeShutter);
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
    QState* acquired = new QState();
    QState* paused = new QState();
    QFinalState* finished = new QFinalState();

    m_machine.addState(idle);
    m_machine.addState(cooling);
    m_machine.addState(settingTemp);
    m_machine.addState(acquiring);
    m_machine.addState(acquired);
    m_machine.addState(paused);
    m_machine.addState(finished);

    m_machine.setInitialState(cooling);

    idle->addTransition(this, &ExperimentController::started, settingTemp);
    cooling->addTransition(this, &ExperimentController::coolingFinished, idle);
    settingTemp->addTransition(this, &ExperimentController::tempSetted, acquiring);
    acquiring->addTransition(this, &ExperimentController::internalSpectrumReady, acquired);
    acquired->addTransition(this, &ExperimentController::continueSweep, settingTemp);
    acquired->addTransition(this, &ExperimentController::finishSweep, idle);
    settingTemp->addTransition(this, &ExperimentController::pauseSweep, paused);
    acquiring->addTransition(this, &ExperimentController::pauseSweep, paused);
    acquired->addTransition(this, &ExperimentController::pauseSweep, paused);
    paused->addTransition(this, &ExperimentController::continueSweep, settingTemp);
    settingTemp->addTransition(this, &ExperimentController::abortSweep, idle);
    acquiring->addTransition(this, &ExperimentController::abortSweep, idle);
    acquired->addTransition(this, &ExperimentController::abortSweep, idle);
    paused->addTransition(this, &ExperimentController::abortSweep, idle);

    // Cooling
    connect(cooling, &QState::entered, [this]() {
        m_spec->coolTo(-60);
        m_ccd_temp_pool.start(1000);
        m_main_window->setStatus("Cooling CCD");
    });

    connect(idle, &QState::entered, [this](){
        m_main_window->setStatus("Idle");
        if(m_aborted) {
            is_started = false;
            is_paused = false;
        }
        m_main_window->enableSpecInputs(true);
        m_main_window->enableCryoInputs(true);
        m_main_window->enableExpInputs(true);
    });

    connect(settingTemp, &QState::entered, [this](){
        m_cryo->setTemperature(m_target);
        m_main_window->setTarget(m_target);
        m_cryo_temp_pool.start(1000);
        m_main_window->setStatus("Setting Sample Temperature");
    });

    connect(acquiring, &QState::entered, [this]() {
        emit m_spec->acquireSpectrum(m_exposure, m_acc);
        m_main_window->setStatus("Acquiring Spectrum");
    });


    connect(acquired, &QState::entered, [this](){
        m_target += m_step;
        if((m_start > m_end && m_target < (m_end-m_step)) || (m_start < m_end && m_target > (m_end+m_step))) {
                is_finished = true;
                is_started = false;
                m_main_window->setStatus("Sweep Finished");
                m_cryo->stopSweep();
                emit finishSweep();
        } else {
        emit continueSweep();
        }
    });

    connect(paused, &QState::entered, [this](){
        m_main_window->setStatus("Sweep Paused");
    });
    m_machine.start();
}

void ExperimentController::start(ExpParams p)
{
    if(is_started) {
        emit continueSweep();
        is_paused = false;
    } else {
        m_start = p.temp_start;
        m_end = p.temp_stop;
        m_step = p.temp_step;
        m_acc = p.acc;
        m_exposure = p.exp_time;
        m_target = m_start;
        m_wavelengthAxis.clear();
        m_temperatures.clear();
        m_intensityMatrix.clear();
        m_cryo->startSweep();
        m_main_window->prepareTempBar(m_start, m_end, m_step);
        is_started = true;
        emit started();
    }
}


void ExperimentController::storeSpectrum(
    double temperature,
    const QVector<float>& wavelength,
    const QVector<long>& intensity)
{
    if (m_wavelengthAxis.isEmpty())
        m_wavelengthAxis = wavelength;

    m_temperatures.append(temperature);
    m_intensityMatrix.append(intensity);
}


ExperimentController::~ExperimentController() {
}

void ExperimentController::receiveSpec(QVector<float> wavelength,
                                       QVector<long> intensity) {
    storeSpectrum(m_target, wavelength, intensity);
    m_main_window->updatePlot(wavelength, intensity);
    m_main_window->updateTempBar(m_target);
    emit internalSpectrumReady();
}

void ExperimentController::pause() {
    is_paused = true;
    emit pauseSweep();
}

void ExperimentController::abort() {
    m_aborted = true;
    emit abortSweep();
}

void ExperimentController::save() {
    if(is_paused || !is_started || is_finished) {
        QString fileName = QFileDialog::getSaveFileName(
            nullptr,
            "Save Temperature Sweep",
            "",
            "CSV Files (*.csv)"
            );

        if (fileName.isEmpty())
            return;

        // Ensure .csv extension
        if (!fileName.endsWith(".csv", Qt::CaseInsensitive))
            fileName += ".csv";

        QFile file(fileName);

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            m_main_window->setStatus("Error: Could not open file for writing.");
            return;
        }

        QTextStream out(&file);
        out.setRealNumberNotation(QTextStream::ScientificNotation);
        out.setRealNumberPrecision(10);

        int N = m_wavelengthAxis.size();
        int M = m_temperatures.size();

        // 1️⃣ Write header (wavelength axis horizontally)
        out << "temperature";

        for (int i = 0; i < N; ++i)
            out << "," << m_wavelengthAxis[i];

        out << "\n";

        // 2️⃣ Write each spectrum as a row
        for (int t = 0; t < M; ++t)
        {
            out << m_temperatures[t];

            for (int w = 0; w < N; ++w)
            {
                if (t < m_intensityMatrix.size() &&
                    w < m_intensityMatrix[t].size())
                {
                    out << "," << m_intensityMatrix[t][w];
                }
                else
                {
                    out << ",0";
                }
            }

            out << "\n";
        }

        file.close();
        m_main_window->setStatus("File saved successfully.");
    }
}
