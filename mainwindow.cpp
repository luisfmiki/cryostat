#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>

#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->start_temp, &QDoubleSpinBox::valueChanged, this, [this](){
        ui->datapoints_temp->setText(QString::number(abs(floor((ui->stop_temp->value()-ui->start_temp->value())/ui->step_temp->value()))+1));
    });
    connect(ui->stop_temp, &QDoubleSpinBox::valueChanged, this, [this](){
        ui->datapoints_temp->setText(QString::number(abs(floor((ui->stop_temp->value()-ui->start_temp->value())/ui->step_temp->value()))+1));
    });
    connect(ui->step_temp, &QDoubleSpinBox::valueChanged, this, [this](){
        ui->datapoints_temp->setText(QString::number(abs(floor((ui->stop_temp->value()-ui->start_temp->value())/ui->step_temp->value()))+1));
    });
    connect(ui->play_button, &QToolButton::clicked, this, [this](){
        ExpParams params;
        params.temp_start = ui->start_temp->value();
        params.temp_stop = ui->stop_temp->value();
        params.temp_step = (params.temp_start>params.temp_stop) ? -1*ui->step_temp->value() : ui->step_temp->value();
        params.exp_time = ui->exposure_time->value();
        params.acc = ui->acc->value();
        emit startSweep(params);
        ui->current_temp->setText(QString::number(params.temp_start));
        enableSpecInputs(false);
        enableCryoInputs(false);
        ui->play_button->setEnabled(false);
        ui->pause_button->setEnabled(true);
        ui->live_plot->setEnabled(false);
        ui->save_button->setEnabled(false);
    });
    connect(ui->slit, &QDoubleSpinBox::editingFinished, this, [this](){
        emit changeSlit(ui->slit->value());
    });

    connect(ui->central_nm, &QDoubleSpinBox::editingFinished, this, [this](){
        //enableSpecInputs(false);
        emit changeWavelength(ui->central_nm->value());
    });

    connect(&m_live_plot_tim, &QTimer::timeout, [this](){
        emit enableLivePlot(true, ui->exposure_time->value(), ui->acc->value());
    });

    connect(ui->live_plot, &QCheckBox::checkStateChanged, this, [this](bool state){
        state ? m_live_plot_tim.start(ui->exposure_time->value()*ui->acc->value()) : m_live_plot_tim.stop();
        enableSpecInputs(!state);
        emit enableLivePlot(state, ui->exposure_time->value(), ui->acc->value());
    });

    connect(ui->pause_button, &QToolButton::clicked, this, [this](){
        emit pauseSweep();
        ui->play_button->setEnabled(true);
        ui->pause_button->setEnabled(false);
        ui->live_plot->setEnabled(true);
        ui->save_button->setEnabled(true);
    });

    connect(ui->abort_button, &QToolButton::clicked, this, [this](){
        emit abortSweep();
        enableSpecInputs(true);
        enableCryoInputs(true);
        ui->play_button->setEnabled(true);
        ui->live_plot->setEnabled(true);
        ui->save_button->setEnabled(true);
    });

    connect(ui->tempBar, &QSlider::actionTriggered, this, [this](){
        showPreviousPlot(ui->tempBar->sliderPosition());
    });

    connect(ui->save_button, &QToolButton::clicked, [this](){
        emit saveData();
    });

    connect(ui->grating_combobox, &QComboBox::currentIndexChanged, this, [this](){
        enableSpecInputs(false);
        emit changeGrating(ui->grating_combobox->currentIndex());
    });

    connect(ui->close_shutter, &QCheckBox::checkStateChanged, this, [this](bool state){
        emit closeShutter(state);
    });

    chart = new QChart();
    chart->setBackgroundBrush(QBrush(QColor(53, 53, 53)));
    m_series = new QLineSeries();
    // Or use a standard Qt color
    chart->legend()->setVisible(false);

    // 3. Configure the Wavelength Axis (X)
    axisX = new QValueAxis();
    axisX->setTitleText("Wavelength (nm)");
    axisX->setRange(380.0, 750.0); // Visible spectrum range
    axisX->setTickCount(10);
    axisX->setLabelsColor(Qt::white);
    axisX->setLabelFormat("%.2f");
    axisX->setTitleBrush(QBrush(Qt::white));
    chart->addAxis(axisX, Qt::AlignBottom);


    // 4. Configure the Intensity Axis (Y)
    axisY = new QValueAxis();
    axisY->setTitleText("Intensity (counts)");
    axisY->setRange(0, 1000);
    axisY->setLabelsColor(Qt::white);
    axisY->setLabelFormat("%d");
    axisY->setTitleBrush(QBrush(Qt::white));
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->addSeries(m_series);
    // Alterar a COR
    chart->setTitleBrush(QBrush(Qt::white));
    // Alterar a FONTE (tamanho, negrito, etc)
    QFont font = chart->titleFont();
    font.setPointSize(18);
    font.setBold(true);
    chart->setTitleFont(font);
    m_series->attachAxis(axisX);
    m_series->attachAxis(axisY);
    m_series->setUseOpenGL(true);
    // 5. Create the View to display the Chart
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->plot_layout->addWidget(chartView);

    ui->pause_button->setEnabled(false);
    ui->abort_button->setEnabled(false);
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

void MainWindow::enableSpecInputs(bool enable) {
    ui->exposure_time->setEnabled(enable);
    ui->acc->setEnabled(enable);
    ui->grating_combobox->setEnabled(enable);
    ui->slit->setEnabled(enable);
    ui->central_nm->setEnabled(enable);
}

void MainWindow::enableCryoInputs(bool enable) {
    ui->start_temp->setEnabled(enable);
    ui->stop_temp->setEnabled(enable);
    ui->step_temp->setEnabled(enable);
}

void MainWindow::enableExpInputs(bool enable) {
    ui->play_button->setEnabled(enable);
    ui->pause_button->setEnabled(enable);
    ui->abort_button->setEnabled(enable);
    ui->save_button->setEnabled(enable);
}

void MainWindow::ccd_temp_update(int temp) {
    ui->ccd_temp->setText(QString::number(temp) + "°C");
    (temp > -59) ?  ui->ccd_temp->setStyleSheet("QLabel { color : red; }") : ui->ccd_temp->setStyleSheet("QLabel { color : green; }");
}

void MainWindow::receiveSpecParams(SpecParams p) {

    ui->slit->setValue(p.slit_width);
    ui->grating_combobox->blockSignals(true);
    ui->grating_combobox->setCurrentIndex(p.grating-1);
    ui->grating_combobox->blockSignals(false);
    ui->central_nm->setValue(p.central_wl);
    ui->close_shutter->blockSignals(true);
    ui->close_shutter->setChecked(!p.shutter_state);
    ui->close_shutter->blockSignals(false);

}

void MainWindow::updatePlot(QVector<float> wavelength, QVector<long> intensity) {
    if(m_first_plot) {
        m_wavelengthAxis = wavelength;
        m_first_plot = false;
        m_counter = 0;
    }
    QVector<QPointF> points;
    points.reserve(wavelength.size()); // Pre-allocate memory to avoid re-allocations

    long maxValue = intensity[0];
    long minValue = intensity[0];

    for (int i = 0; i < wavelength.size(); ++i) {
        points.append(QPointF(wavelength[i], intensity[i]));

        // Efficiency Tip: Calculate min/max here to avoid extra loops
        if (intensity[i] > maxValue) maxValue = intensity[i];
        if (intensity[i] < minValue) minValue = intensity[i];
    }

    // 3. Update Axes
    axisX->setRange(wavelength.first(), wavelength.last());
    axisY->setRange(minValue - 10, maxValue + 10);

    // 4. The "Fast" Swap
    m_series->replace(points);
    max_elements.append(maxValue);
    min_elements.append(minValue);
    m_intensityMatrix.append(intensity);
}


void MainWindow::prepareTempBar(double low, double upper, double step){
    m_max_cnt = abs(floor((upper-low)/step))+1;
    ui->tempBar->setRange(0, m_max_cnt-1);
    ui->tempBar->setSingleStep(1);
    ui->tempBar->setValue(0);
    m_counter = 0;

}

void MainWindow::updateTempBar(double temp) {
    ui->tempBar->setValue(m_counter);
    chart->setTitle(QString::number(temp) + "K");
    m_temperatures.append(temp);
    m_counter++;
    if(m_counter > m_max_cnt) m_first_plot = true;
}

void MainWindow::showPreviousPlot(int value){
    if(value >= m_counter) return;
    QVector<QPointF> points;
    points.reserve(m_wavelengthAxis.size()); // Pre-allocate memory to avoid re-allocations
    QVector<long> intensity = m_intensityMatrix[value];
    for (int i = 0; i < m_wavelengthAxis.size(); ++i) {
        points.append(QPointF(m_wavelengthAxis[i], intensity[i]));
    }
    axisY->setRange(min_elements[value] - 10, max_elements[value]+10);
    axisX->setRange(m_wavelengthAxis[0], m_wavelengthAxis[m_wavelengthAxis.size()-1]);
    // 3. Update Axe

    // 4. The "Fast" Swap
    m_series->replace(points);
    chart->setTitle(QString::number(m_temperatures[value]) + "K");
}

void MainWindow::livePlot(QVector<float> wavelength, QVector<long> intensity) {
    QVector<QPointF> points;
    points.reserve(wavelength.size()); // Pre-allocate memory to avoid re-allocations

    long maxValue = intensity[0];
    long minValue = intensity[0];

    for (int i = 0; i < wavelength.size(); ++i) {
        points.append(QPointF(wavelength[i], intensity[i]));

        // Efficiency Tip: Calculate min/max here to avoid extra loops
        if (intensity[i] > maxValue) maxValue = intensity[i];
        if (intensity[i] < minValue) minValue = intensity[i];
    }

    // 3. Update Axes
    axisX->setRange(wavelength.first(), wavelength.last());
    axisY->setRange(minValue - 10, maxValue + 10);

    // 4. The "Fast" Swap
    m_series->replace(points);
}

void MainWindow::setStatus(QString status) {
    ui->status->setText(status);
}

void MainWindow::showCryoTemp(double temp) {
    ui->cryo_temp_status->setText(QString::number(temp)+"K");
}

void MainWindow::changedGrating() {
    enableSpecInputs(true);
}

void MainWindow::changedWavelength() {
    enableSpecInputs(true);
}
void MainWindow::setTarget(double temp) {
    ui->current_temp->setText(QString::number(temp));
}

void MainWindow::finishSweep() {
    ui->play_button->setEnabled(true);
}
