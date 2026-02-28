#ifndef EXPERIMENT_H
#define EXPERIMENT_H
#pragma once

#include <QObject>
#include <QStateMachine>
#include <QVector>
#include <QString>
#include <QTimer>


class CryostatController;
class SpectrometerController;
class MainWindow;

typedef struct ExpParams{
    double temp_start;
    double temp_stop;
    double temp_step;
    double exp_time;
    unsigned int acc;
} ExpParams;
typedef struct SpecParams{
    float slit_width;
    int grating;
    float central_wl;
    int shutter_state;
} SpecParams;


class ExperimentController : public QObject
{
    Q_OBJECT

public:
    explicit ExperimentController(CryostatController* cryo,
                                  SpectrometerController* spec,
                                  MainWindow* main_window,
                                  QObject* parent = nullptr);
    ~ExperimentController();

    void setOutputFile(const QString& filePath);

public slots:
    void start(ExpParams p);
    void receiveSpec(QVector<float> wavelength,
                     QVector<long> intensity);
    void pause();
    void abort();
    void save();

signals:
    void started();
    void coolingFinished();
    void temperatureReached(double temperature);
    void internalSpectrumReady();
    void experimentFinished();
    void experimentAborted();
    void updateCCDTemp(int ccd_temperature);
    void tempSetted();
    void continueSweep();
    void finishSweep();
    void pauseSweep();
    void abortSweep();

private:
    void setupStateMachine();
    void storeSpectrum(double temperature,
                       const QVector<float>& wavelength,
                       const QVector<long>& intensity);
    void writeCsvFile();

    CryostatController* m_cryo;
    SpectrometerController* m_spec;
    MainWindow* m_main_window;

    QStateMachine m_machine;

    double m_start = 0.0;
    double m_end = 0.0;
    double m_step = 0.0;
    double m_current_temp = 0.0;
    double m_target;
    double m_exposure;
    int m_acc;

    QString m_outputFilePath;

    QVector<float> m_wavelengthAxis;              // size = pixels
    QVector<double> m_temperatures;                // size = Ntemps
    QVector<QVector<long>> m_intensityMatrix;    // [tempIndex][pixelIndex]

    QTimer m_ccd_temp_pool;
    QTimer m_cryo_temp_pool;
    QTimer m_cryo_temp_pool_a;
    bool cooling_finished = false;
    bool is_started = false;
    bool is_finished = false;
    bool is_paused = false;
    bool m_aborted = false;
    int m_stable_cnt = 0;
};
#endif // EXPERIMENT_H
