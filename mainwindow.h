#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "experiment.h"
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

class ExperimentController;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setCryoConnStatus(bool status);
    void setSpecConnStatus(bool status);
    void enableSpecInputs(bool enable);
    void enableCryoInputs(bool enable);
    void enableExpInputs(bool enable);
    void receiveSpecParams(SpecParams p);
    void prepareTempBar(double low, double upper, double step);
    void updatePlot(QVector<float> wavelength, QVector<long> intensity);
    void updateTempBar(double temp);
    void livePlot(QVector<float> wavelength, QVector<long> intensity);
    void setStatus(QString status);
    void setTarget(double temp);

public slots:
    void ccd_temp_update(int temp);
    void showCryoTemp(double temp);
    void changedGrating();
    void changedWavelength();
    void finishSweep();

signals:
    void startSweep(ExpParams params);
    void changeSlit(double value);
    void changeGrating(int grating);
    void changeWavelength(double wl);
    void enableLivePlot(bool enable, double exp, int acc);
    void pauseSweep();
    void abortSweep();
    void saveData();
    void closeShutter(bool close);

private:
    Ui::MainWindow *ui;
    int m_current_grating;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QChart *chart;
    QChartView *chartView;
    QVector<double> m_wl;
    bool m_first_plot = true;
    QVector<float> m_wavelengthAxis;              // size = pixels
    QVector<double> m_temperatures;                // size = Ntemps
    QVector<QVector<long>> m_intensityMatrix;    // [tempIndex][pixelIndex]
    QVector<long> max_elements, min_elements;
    int m_counter;
    void showPreviousPlot(int value);
    int m_max_cnt;
    QLineSeries* m_series;
    QTimer m_live_plot_tim;
};
#endif // MAINWINDOW_H
