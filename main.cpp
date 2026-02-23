#include "mainwindow.h"

#include <QApplication>
#include "cryostat.h"
#include "spectrometer.h"
#include "experiment.h"
#include "darkstyle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(new DarkStyle);
    MainWindow w;

    CryostatController cryo;
    if(cryo.initialize() != ATTOCUBE_Ok) {
        w.setCryoConnStatus(false);
        w.enableInputs(false);
    } else {
        w.setCryoConnStatus(true);
    }

    SpectrometerController spec;
    if(spec.initialize()) {
        w.setSpecConnStatus(false);
        w.enableInputs(false);
    } else {
        w.setSpecConnStatus(true);
    }

    ExperimentController exp(&cryo, &spec);

    w.show();
    return a.exec();
}
