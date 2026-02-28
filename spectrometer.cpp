#include "spectrometer.h"
#include <vector>
#include <thread>

SpectrometerController::SpectrometerController(QObject* parent)
    : QObject(parent)
{
}

int SpectrometerController::initialize()
{
    char path[] = "";
    if (Initialize(path) != DRV_SUCCESS) {
        //emit error("Camera init failed");
        return 1;
    }

    if (ATSpectrographInitialize(nullptr) != ATSPECTROGRAPH_SUCCESS) {
        return 1;
    }
    GetDetector(&m_width, &m_height);
    SetImage(1, 1, 1, m_width, 1, m_height);
    SetReadMode(0);              // FVB
    SetAcquisitionMode(1);       // Singles
    ATSpectrographSetNumberPixels(0, m_width);
    ATSpectrographSetPixelWidth(0, 26);
    m_wavelength.resize(m_width);
    ATSpectrographGetCalibration(0, m_wavelength.data(), m_width);
    //ATSpectrographSetShutter(0, SHUTTER_OPEN);
    ATSpectrographSetFlipperMirror(0, INPUT_FLIPPER, DIRECT);
    ATSpectrographSetFlipperMirror(0, OUTPUT_FLIPPER, SIDE);
    return 0;
}


void SpectrometerController::coolTo(double temperatureC)
{
    SetTemperature(static_cast<int>(temperatureC));
    CoolerON();
}

bool SpectrometerController::waitForTemperature()
{
    int temp;
    int status;

    while (true)
    {
        status = GetTemperature(&temp);
        emit temperatureUpdated(temp);

        if (status == DRV_TEMP_STABILIZED)
            return true;

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void SpectrometerController::acquireSpectrum(double exp, int acc)
{

    SetExposureTime((float)(exp/1000));
    SetNumberAccumulations(acc);

    StartAcquisition();
    WaitForAcquisition();

    QVector<long> buffer(m_width);

    GetAcquiredData(buffer.data(), m_width);

    emit spectrumReady(m_wavelength, buffer);
}

void SpectrometerController::checkCCDTemp(int *temperature) {
    GetTemperature(temperature);
    emit ccdTempReadReady(*temperature);
}

SpectrometerController::~SpectrometerController(){
    CoolerOFF();
}

void SpectrometerController::changeSlit(double value){
    ATSpectrographSetSlitWidth(0, INPUT_SIDE, static_cast<float>(value));
}

void SpectrometerController::changeGrating(int grating) {
    if (grating == 0) {
        if(m_grating == 0) return;
        ATSpectrographSetGrating(0, 1);
        m_grating = 0;
    }
    if (grating == 1) {
        if(m_grating == 1) return;
        ATSpectrographSetGrating(0, 2);
        m_grating = 1;
    }
    if (grating == 2) {
        if(m_grating == 2) return;
        ATSpectrographSetGrating(0, 3);
        m_grating = 2;
    }
    ATSpectrographGetCalibration(0, m_wavelength.data(), m_width);
    emit gratingChanged();
}

SpecParams SpectrometerController::currentParameters() {
    SpecParams p;
    ATSpectrographGetGrating(0, &p.grating);
    m_grating = p.grating - 1;
    ATSpectrographGetSlitWidth(0, INPUT_SIDE, &p.slit_width);
    m_slit = p.slit_width;
    ATSpectrographGetWavelength(0, &p.central_wl);
    eATSpectrographShutterMode s;
    ATSpectrographGetShutter(0, &s);
    p.shutter_state = s;
    m_shutter = s;
    return p;
}

void SpectrometerController::changeWavelength(double wl) {
    ATSpectrographSetWavelength(0, static_cast<float>(wl));
    ATSpectrographGetCalibration(0, m_wavelength.data(), m_width);
    emit changedWavelength();
}

void SpectrometerController::livePlot(bool enable, double exp, int acc) {
    if(m_first_liveplot) {
        m_exp = exp;
        m_acc = acc;
        SetExposureTime((float)(exp/1000));
        SetNumberAccumulations(acc);
        m_first_liveplot = false;
    }
    if(!enable) m_first_liveplot = true;
    else {
        StartAcquisition();
        WaitForAcquisition();

        QVector<long> buffer(m_width);

        GetAcquiredData(buffer.data(), m_width);
        emit liveSpecReady(m_wavelength, buffer);
    }
}

void SpectrometerController::closeShutter(bool close) {
    ATSpectrographSetShutter(0, close ? SHUTTER_CLOSED : SHUTTER_OPEN);
}
