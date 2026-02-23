#include "spectrometer.h"
#include "ATMCD32D.H"
#include "ShamrockCIF.h"
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

    if (ShamrockInitialize(path) != DRV_SUCCESS) {
        return 1;
    }
    GetDetector(&m_width, nullptr);
    return 0;
}

void SpectrometerController::configure(double exposure,
                                       int accumulations,
                                       int gratingLines,
                                       double gratingPositionNm,
                                       double slitWidthMicrons)
{
    SetReadMode(0);              // FVB
    SetAcquisitionMode(1);       // Single
    SetExposureTime(exposure);
    SetNumberAccumulations(accumulations);

    // Select grating
    if (gratingLines == 300) ShamrockSetGrating(0, 1);
    if (gratingLines == 600) ShamrockSetGrating(0, 2);
    if (gratingLines == 1200) ShamrockSetGrating(0, 3);

    ShamrockSetWavelength(0, gratingPositionNm);
    ShamrockSetAutoSlitWidth(0, 1, slitWidthMicrons);
}

void SpectrometerController::coolTo(double temperatureC)
{
    SetTemperature(static_cast<int>(temperatureC));
    CoolerON();

    if (waitForTemperature())
        emit coolingReady();
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

void SpectrometerController::acquireSpectrum()
{
    StartAcquisition();
    WaitForAcquisition();

    std::vector<long> buffer(m_width);
    GetAcquiredData(buffer.data(), m_width);

    QVector<double> intensity(m_width);
    QVector<double> wavelength(m_width);

    std::vector<float> wl(m_width);
    ShamrockGetCalibration(0, wl.data(), m_width);

    for (int i = 0; i < m_width; ++i) {
        intensity[i] = buffer[i];
        wavelength[i] = wl[i];
    }

    emit spectrumReady(wavelength, intensity);
}
