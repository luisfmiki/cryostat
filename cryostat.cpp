#include "cryostat.h"
#include <QThread>
#include <cmath>


CryostatController::CryostatController(QObject* parent)
    : QObject(parent)
{
    connect(&m_pollTimer, &QTimer::timeout, this, [this]() {

        int status;
        double current_temp;
        status = attoDry_sample_getTemperature(m_handle, &current_temp);
        if(status == ATTOCUBE_Ok) {
            emit temperatureUpdated(current_temp);
            if (isTemperatureStable(current_temp, m_current_target)) {
                emit temperatureStabilized(current_temp);
            }
        }
    });
}

int CryostatController::initialize()
{
    // TODO: initialize attoDRY SDK connection
    return Connect(m_addr, &m_handle);
}

void CryostatController::startSweep(double startK, double endK, double stepK)
{
    m_start = startK;
    m_end = endK;
    m_step = stepK;
    m_current_target = startK;
    m_running = true;
    if(attoDry_sample_startTempControl(m_handle) != ATTOCUBE_Ok) return;
    if(setTemperature(m_current_target)) return;
    m_pollTimer.start(1000); // poll every 1 seconds
}

void CryostatController::stopSweep()
{
    m_running = false;
    m_pollTimer.stop();
    attoDry_sample_stopTempControl(m_handle);
}

int CryostatController::setTemperature(double kelvin)
{
    // TODO: attoDRY set temperature API call
    if(attoDry_sample_setSetPoint(m_handle, kelvin) != ATTOCUBE_Ok) return 1;
    return 0;
}

bool CryostatController::isTemperatureStable(double current, double target)
{
    return std::abs(current - target) < 0.1;  // 100 mK tolerance
}

void CryostatController::specAcquired() {
    m_current_target += m_step;
    //setTemperature(m_current_target);
}
