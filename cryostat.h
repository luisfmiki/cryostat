#ifndef CRYOSTAT_H
#define CRYOSTAT_H
#pragma once

#include <QObject>
#include <QTimer>
#include "external/attocube/attocubeJSONCall.h"
#include "external/attocube/attoDry.h"
#include "experiment.h"

class CryostatController : public QObject
{
    Q_OBJECT

public:
    explicit CryostatController(QObject* parent = nullptr);
    ~CryostatController();
    int initialize();
    int setTemperature(double kelvin);
    double getTemperature();
    void startSweep();
    void stopSweep();
    bool isTemperatureStable(double current, double target);

signals:
    void temperatureUpdated(double temperature);
    void temperatureStabilized(double temperature);
    void sweepFinished();
    void error(QString message);

private:


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
