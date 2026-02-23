#ifndef CRYOSTAT_H
#define CRYOSTAT_H
#pragma once

#include <QObject>
#include <QTimer>
#include "external/attocube/attocubeJSONCall.h"
#include "external/attocube/attoDry.h"

class CryostatController : public QObject
{
    Q_OBJECT

public:
    explicit CryostatController(QObject* parent = nullptr);
    int initialize();
    int setTemperature(double kelvin);

public slots:
    void startSweep(double startK, double endK, double stepK);
    void stopSweep();
    void specAcquired();

signals:
    void temperatureUpdated(double temperature);
    void temperatureStabilized(double temperature);
    void sweepFinished();
    void error(QString message);

private:
    bool isTemperatureStable(double current, double target);

    double m_start;
    double m_end;
    double m_step;
    double m_current_target;
    bool m_running = false;

    QTimer m_pollTimer;

    int m_handle;
    const char* m_addr = "192.168.1.1";
};
#endif // CRYOSTAT_H
