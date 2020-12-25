#include "coorddescdial.h"
#include "ui_coorddescdial.h"

CoordDescDial::CoordDescDial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CoordDescDial)
{
    ui->setupUi(this);
}

CoordDescDial::~CoordDescDial()
{
    delete ui;
}

void CoordDescDial::setAccuracy(double value){
    accuracy=value;
}
double CoordDescDial::getAccuracy(){
    return accuracy;
}
void CoordDescDial::setLen(double value){
    len=value;
}
double CoordDescDial::getLen(){
    return len;
}


void CoordDescDial::on_buttonBox_accepted()
{
    setLen(ui->doubleSpinBox_len->value());
    setAccuracy(ui->doubleSpinBox->value());

}
