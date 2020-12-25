#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "funcOpt.h"
#include "area.h"
#include "stopCrit.h"
#include "optmethod.h"
#include <vector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setValue(int );
    void createFunc(int );
    void setIterNum(int );
    void setStoch(double ,double);
    void setCD(double,double);
    void setStop1(int);
    void setStop2(double);
    void setStop3();
    void setAreaEasy();
    void setAreaHard(std::vector<std::pair<double,double>>);
    int getValue();
signals:
    void valueChanged(QString displayValue, int value);
private slots:
    void on_radioButton_4_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_doubleSpinBox_editingFinished();

    void on_comboBox_currentIndexChanged(int index);

    void on_incrementButton_clicked();

    void mousePressEvent(QMouseEvent*);

private:
    Ui::MainWindow *ui;
    int a;
    func* f=new func_1;
    OptMethod * method=nullptr;
    StopCriteria* stop=nullptr;
    area * my_area=nullptr;
    int num_of_iter;
    double xclick,yclick;
};
#endif // MAINWINDOW_H
