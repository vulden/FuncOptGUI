#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "areadialog.h"
#include "localsdial.h"
#include "coorddescdial.h"
#include "stopcrit1.h"
#include "stopcrit2.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->widget, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePressEvent(QMouseEvent*)));
  //  connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
  //  connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::createFunc(int value){
    if(f) delete f;
    switch (value) {
    case 0:{
        f = new func_1();
        break;
    }
    case 1:{
        f = new func_3();
        break;
    }
    case 2:{
        f = new func_2();
        break;
    }
    case 3:{
        f = new func_4();
        break;
    }
    }
    if(my_area)
    {
        drawMap();
    ui->widget->replot();
    }
}
void MainWindow::setStoch(double v1,double v2){
    if(method) delete method;
     method = new Stochastic;
     method->set_p(v1);
     method->set_delta(v2);
}
void MainWindow::setCD(double v1,double v2){
    if(method) delete method;
    method = new CoordDescent;
    method->set_len_of_seg(v1);
    method ->set_eps(v2);
}
void MainWindow::setStop1(int v){
    if(stop) delete stop;
    stop = new StopValLI(0,v);
}
void MainWindow::setStop2(double v){
    if(stop) delete stop;
    stop = new StopNumLI(v,0);
}
void MainWindow::setStop3(){
    if(stop) delete stop;
    stop = new StopNULL();
}
void MainWindow::setAreaEasy(){
    if(my_area) delete my_area;
    my_area = new area_easy(2);
}
void MainWindow::setAreaHard(std::vector<std::pair<double,double>> coord){
    if(my_area) delete my_area;
    my_area= new area_hard(coord);
}

void MainWindow::setIterNum(int v){
    num_of_iter=v;
}

void MainWindow::on_radioButton_4_clicked() //area hard
{
    areadialog a;
    if( a.exec() == QDialog::Accepted){
    std::vector<std::pair<double,double>> coord;
    coord.push_back(std::make_pair(a.x1,a.y1));
    coord.push_back(std::make_pair(a.x2,a.y2));
    setAreaHard(coord);
    drawMap();
    ui->widget->replot();

    }
}

void MainWindow::on_radioButton_clicked()
{

    CoordDescDial a;
    if(a.exec() == QDialog::Accepted){
    setCD(a.getLen(),a.getAccuracy());
    }
}

void MainWindow::on_radioButton_2_clicked()
{
    LocalSDial a;
    if( a.exec() == QDialog::Accepted){
    setStoch(a.getP(),a.getDelta());
    }
}
void MainWindow::on_radioButton_5_clicked()
{
    setStop3();
}

void MainWindow::on_radioButton_6_clicked()
{
    StopCrit2 a;
    if(a.exec() == QDialog::Accepted){
    setStop2(a.getv());
    }
}

void MainWindow::on_radioButton_7_clicked()
{
    StopCrit1 a;
     if( a.exec() == QDialog::Accepted){
     setStop1(a.getv());
     }
}

void MainWindow::on_doubleSpinBox_editingFinished()
{
   setIterNum(ui->doubleSpinBox->value());
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    createFunc(index);
}

void MainWindow::on_radioButton_3_clicked() //area easy
{
    setAreaEasy();
    drawMap();
    ui->widget->replot();
}

void MainWindow::drawMap(){
    double xmin=my_area->coord[0].first,xmax=my_area->coord[0].second, ymin=my_area->coord[1].first,ymax=my_area->coord[1].second;
    QCPColorMap *colorMap = new QCPColorMap(ui->widget->xAxis, ui->widget->yAxis);
    colorMap->data()->setSize(705, 315);
    colorMap->data()->setRange(QCPRange(xmin, xmax), QCPRange(ymin, ymax));
    for (int x=0; x<705; ++x)
      for (int y=0; y<315; ++y)
      {
          std::vector<double> temp;
          temp.push_back(xmin + x * (xmax - xmin) / 705);
          temp.push_back(ymin + y * (ymax - ymin) / 315);
        colorMap->data()->setCell(x, y, f->eval(temp));
      }
    colorMap->setGradient(QCPColorGradient::gpPolar);
    colorMap->rescaleDataRange(true);
    ui->widget->rescaleAxes();
}
void MainWindow::mousePressEvent(QMouseEvent* event)
{
    xclick=ui->widget->xAxis->pixelToCoord(event->x());
    yclick=ui->widget->yAxis->pixelToCoord(event->y());
    if(event->x()<40 || event->x()>700 || event->y()<25 || event->y()>300) return;
    if(!my_area || !stop || !method){
        QMessageBox::warning(this, "ERROR", "Choose all the parameters.");
        return;
    }
    setIterNum(ui->doubleSpinBox->value());
    std::vector<std::vector<double>> path;
    std::vector<double> result;
    result.push_back(xclick);
    result.push_back(yclick);
        path=method->optimize(f,my_area,stop,result,num_of_iter);

    drawMap();
    QCPCurve* tcCurve = new QCPCurve(ui->widget->xAxis, ui->widget->yAxis);
    QCPCurve* Curve1 = new QCPCurve(ui->widget->xAxis, ui->widget->yAxis);
    QCPCurve* Curve2 = new QCPCurve(ui->widget->xAxis, ui->widget->yAxis);
    Curve1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    Curve2->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    Curve1->setPen(QPen(QColor(255, 0, 0)));
    Curve2->setPen(QPen(QColor(255, 255, 0)));
    tcCurve->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    tcCurve->setPen(QPen(QColor(255, 255, 255)));
    for(int i = 0; i < path.size(); ++i)
        tcCurve->addData(i, path[i][0], path[i][1]);
    Curve1->addData(0, path[0][0], path[0][1]);
    Curve2->addData(0, path[path.size()-1][0], path[path.size()-1][1]);

    ui->widget->rescaleAxes();
    ui->widget->replot();
    ui->label_5->setText(QString::number(event->x()));
    ui->label_6->setText(QString::number(event->y()));
    ui->label_9->setText(QString::number(f->eval(path[path.size()-1])));
}
/*void MainWindow::on_incrementButton_clicked()
{
    if(!my_area || !stop || !method){
        QMessageBox::warning(this, "ERROR", "Choose all the parameters.");
        return;
    }
    setIterNum(ui->doubleSpinBox->value());
   std::vector<std::vector<double>> path;
   std::vector<double> result;
    result.push_back(xclick);
    result.push_back(yclick);
        path=method->optimize(f,my_area,stop,result,num_of_iter);

    double xmin=my_area->coord[0].first,xmax=my_area->coord[0].second, ymin=my_area->coord[1].first,ymax=my_area->coord[1].second;
    QCPColorMap *colorMap = new QCPColorMap(ui->widget->xAxis, ui->widget->yAxis);
    colorMap->data()->setSize(705, 315);
    colorMap->data()->setRange(QCPRange(xmin, xmax), QCPRange(ymin, ymax));
    for (int x=0; x<705; ++x)
      for (int y=0; y<315; ++y)
      {
          std::vector<double> temp;
          temp.push_back(xmin + x * (xmax - xmin) / 705);
          temp.push_back(ymin + y * (ymax - ymin) / 315);
        colorMap->data()->setCell(x, y, f->eval(temp));
      }
    colorMap->setGradient(QCPColorGradient::gpPolar);
    colorMap->rescaleDataRange(true);
    QCPCurve* tcCurve = new QCPCurve(ui->widget->xAxis, ui->widget->yAxis);
    QCPCurve* Curve1 = new QCPCurve(ui->widget->xAxis, ui->widget->yAxis);
    QCPCurve* Curve2 = new QCPCurve(ui->widget->xAxis, ui->widget->yAxis);
    Curve1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    Curve2->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    Curve1->setPen(QPen(QColor(255, 0, 0)));
    Curve2->setPen(QPen(QColor(255, 255, 0)));
    tcCurve->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    tcCurve->setPen(QPen(QColor(255, 255, 255)));
    for(int i = 0; i < path.size(); ++i)
        tcCurve->addData(i, path[i][0], path[i][1]);
    Curve1->addData(0, path[0][0], path[0][1]);
    Curve2->addData(0, path[path.size()-1][0], path[path.size()-1][1]);

    ui->widget->rescaleAxes();
    ui->widget->replot();
    ui->label_5->setText(QString::number(path[path.size()-1][0]));
    ui->label_6->setText(QString::number(path[path.size()-1][1]));
    ui->label_9->setText(QString::number(f->eval(path[path.size()-1])));
    //ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}*/
