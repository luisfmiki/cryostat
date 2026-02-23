#ifndef EXPERIMENT_H
#define EXPERIMENT_H
#pragma once

#include <QObject>
#include <QStateMachine>
#include <QVector>
#include <QString>

class CryostatController;
class SpectrometerController;

class ExperimentController : public QObject
{
    Q_OBJECT

public:
    explicit ExperimentController(CryostatController* cryo,
                                  SpectrometerController* spec,
                                  QObject* parent = nullptr);

    void setOutputFile(const QString& filePath);

public slots:
    void start(double startK, double endK, double stepK);
    void pause();
    void resume();
    void abort();

signals:
    void startRequested();
    void coolingFinished();
    void temperatureReached(double temperature);
    void internalSpectrumReady(QVector<double> wavelength,
                               QVector<double> intensity);
    void experimentFinished();
    void experimentAborted();

private:
    void setupStateMachine();
    void advanceTemperature();
    void storeSpectrum(double temperature,
                       const QVector<double>& wavelength,
                       const QVector<double>& intensity);
    void writeCsvFile();

    CryostatController* m_cryo;
    SpectrometerController* m_spec;

    QStateMachine m_machine;

    double m_start = 0.0;
    double m_end = 0.0;
    double m_step = 0.0;
    double m_currentTemp = 0.0;

    QString m_outputFilePath;

    QVector<double> m_wavelengthAxis;              // size = pixels
    QVector<double> m_temperatures;                // size = Ntemps
    QVector<QVector<double>> m_intensityMatrix;    // [tempIndex][pixelIndex]
};
#endif // EXPERIMENT_H
