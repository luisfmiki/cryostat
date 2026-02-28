#ifndef SPECTROMETER_H
#define SPECTROMETER_H
#pragma once

#include <QObject>
#include <QVector>
#include "ATMCD32D.H"
#include "ATSpectrograph.h"
#include "ShamrockCIF.h"
#include "experiment.h"

class SpectrometerController : public QObject
{
    Q_OBJECT

public:
    explicit SpectrometerController(QObject* parent = nullptr);
    ~SpectrometerController();

    SpecParams currentParameters();
    QVector<float> m_wavelength;

public slots:
    int initialize();
    void acquireSpectrum(double exp, int acc);
    void coolTo(double temperatureC);

    void changeSlit(double value);
    void changeGrating(int grating);
    void changeWavelength(double wl);
    void livePlot(bool enable, double exp, int acc);
    void checkCCDTemp(int *temperature);
    void closeShutter(bool close);


signals:
    void temperatureUpdated(int tempC);
    void coolingReady();
    void spectrumReady(QVector<float> wavelength,
                       QVector<long> intensity);
    void error(QString message);
    void liveSpecReady(QVector<float> wavelength,
                       QVector<long> intensity);
    void gratingChanged();
    void changedWavelength();
    void ccdTempReadReady(int temp);

private:
    bool waitForTemperature();
    int m_grating;
    int m_slit;
    int m_width;
    int m_height;
    int m_shutter;
    bool m_liveplot_en = false;
    double m_exp;
    int m_acc;
    QTimer live_plot_tim;
    bool m_first_liveplot = true;
};
#endif // SPECTROMETER_H
