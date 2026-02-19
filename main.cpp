#include "mainwindow.h"

#include <QApplication>
#include "external/attocube/attocubeJSONCall.h"
#include "external/attocube/attoDry.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    const char* device = "192.168.1.1";

    int deviceHandle;
    int error = Connect(device, &deviceHandle);
    if(error == ATTOCUBE_Ok) {
        qDebug() << "connected";
        double sample_tempature;
        int ret_val = attoDry_sample_getTemperature(deviceHandle, &sample_tempature);
        if(ret_val == ATTOCUBE_Ok) {
            qDebug() << "Sample Temperature: " << sample_tempature;
        }
        // double exchange_temperature;
        // ret_val = attoDry_exchange_getTemperature(deviceHandle, &exchange_temperature);
        // if(ret_val == ATTOCUBE_Ok) {
        //     qDebug() << "Sample Temperature: " << exchange_temperature;
        // }
        // int ret_val = attoDry_sample_startTempControl(deviceHandle);
        // if(ret_val == ATTOCUBE_Ok) {
        //     qDebug() << "Set Point made";
        // }
        // ret_val = attoDry_sample_stopTempControl(deviceHandle);
        // if(ret_val == ATTOCUBE_Ok) {
        //     qDebug() << "turned temp controll off";
        // }
        // bool status;
        // ret_val = attoDry_sample_getTempControlStatus(deviceHandle, &status);
        // if(ret_val == ATTOCUBE_Ok) {
        //     qDebug() << "heater status: " << status;
        // }

        error = Disconnect(deviceHandle);
    }
    else qDebug() << "not connected";
    MainWindow w;
    w.show();
    return a.exec();
}
