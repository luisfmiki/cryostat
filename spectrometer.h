#ifndef SPECTROMETER_H
#define SPECTROMETER_H
#pragma once

#include <QObject>
#include <QVector>

class SpectrometerController : public QObject
{
    Q_OBJECT

public:
    explicit SpectrometerController(QObject* parent = nullptr);

public slots:
    int initialize();
    void configure(double exposure,
                   int accumulations,
                   int gratingLines,
                   double gratingPositionNm,
                   double slitWidthMicrons);

    void coolTo(double temperatureC);
    void acquireSpectrum();

signals:
    void temperatureUpdated(int tempC);
    void coolingReady();
    void spectrumReady(QVector<double> wavelength,
                       QVector<double> intensity);
    void error(QString message);

private:
    bool waitForTemperature();

    int m_width = 0;
};
#endif // SPECTROMETER_H
