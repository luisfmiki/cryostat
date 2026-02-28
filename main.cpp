#include "mainwindow.h"

#include <QApplication>
#include "cryostat.h"
#include "spectrometer.h"
#include "experiment.h"
#include "darkstyle.h"
#include <QSplashScreen>
#include <QPixmap>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(new DarkStyle);
    QPixmap pix(":/images/splash.png");
    QSplashScreen splash(pix);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - pix.width()) / 2;
    int y = (screenGeometry.height() - pix.height()) / 2;
    splash.move(x, y);
    splash.show();
    a.processEvents();
    MainWindow w;
    a.setWindowIcon(QIcon(":/resources/fabns.ico"));
    CryostatController cryo;
    if(cryo.initialize() != ATTOCUBE_Ok) {
        w.setCryoConnStatus(false);
        w.enableCryoInputs(false);
    } else {
        w.setCryoConnStatus(true);
    }

    SpectrometerController spec;
    if(spec.initialize()) {
        w.setSpecConnStatus(false);
        w.enableSpecInputs(false);
    } else {
        w.setSpecConnStatus(true);
    }
    w.enableExpInputs(false);
    ExperimentController exp(&cryo, &spec, &w);
    splash.finish(&w);
    w.showMaximized();
    w.setWindowTitle("CryoSpec - Custom cryogenic-spectroscopy app for Xubaka");
    w.show();
    return a.exec();
}
