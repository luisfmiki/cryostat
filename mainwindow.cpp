#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect(ui->startButton, &QPushButton::clicked,
    //         [=]() {
    //             experiment->startSweep(
    //                 ui->startTemp->value(),
    //                 ui->endTemp->value(),
    //                 ui->stepTemp->value());
    //         });

    // connect(ui->pauseButton, &QPushButton::clicked,
    //         experiment, &ExperimentController::pause);

    // connect(ui->abortButton, &QPushButton::clicked,
    //         experiment, &ExperimentController::abort);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCryoConnStatus(bool status) {
    if(!status) {
        ui->cryo_connect->setText("Off");
        ui->cryo_connect->setStyleSheet("QLabel { color : red; }");
    } else {
        ui->cryo_connect->setText("On");
        ui->cryo_connect->setStyleSheet("QLabel { color : green; }");
    }
}

void MainWindow::setSpecConnStatus(bool status) {
    if(!status) {
        ui->spec_connect->setText("Off");
        ui->spec_connect->setStyleSheet("QLabel { color : red; }");
    } else {
        ui->spec_connect->setText("On");
        ui->spec_connect->setStyleSheet("QLabel { color : green; }");
    }
}

void MainWindow::enableInputs(bool enable) {
    this->enableInputs(enable);
}
