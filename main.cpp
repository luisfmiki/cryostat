#include "mainwindow.h"

#include <QApplication>
#include "external/attocube/attocubeJSONCall.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    const char* device = "10.99.70.238";

    int deviceHandle;
    int error = Connect(device, &deviceHandle);
    if(error == ATTOCUBE_Ok) qDebug() << "connected";
    else qDebug() << "not connected";
    MainWindow w;
    w.show();
    return a.exec();
}
