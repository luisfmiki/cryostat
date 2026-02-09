#include "mainwindow.h"

#include <QApplication>
#include "external/attocube/attocubeJSONCall.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    const char* device = "10.99.70.238";

    int deviceHandle;
    int error = Connect(device, &deviceHandle);
    return a.exec();
}
