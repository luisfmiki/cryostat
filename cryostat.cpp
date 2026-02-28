#include "cryostat.h"
#include <QThread>
#include <cmath>


CryostatController::CryostatController(QObject* parent)
    : QObject(parent)
{
}

int CryostatController::initialize()
{
    // TODO: initialize attoDRY SDK connection
    return Connect(m_addr, &m_handle);
}

void CryostatController::startSweep()
{
    if(attoDry_sample_startTempControl(m_handle) != ATTOCUBE_Ok) return;
}

void CryostatController::stopSweep()
{
    m_running = false;
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
    return std::abs(current - target) < 0.01;  // 50 mK tolerance
}


CryostatController::~CryostatController(){
    attoDry_sample_stopTempControl(m_handle);
}

double CryostatController::getTemperature(){
    double current_temp;
    attoDry_sample_getTemperature(m_handle, &current_temp);
    return current_temp;
}
