#include "stopcrit1.h"
#include "ui_stopcrit1.h"

StopCrit1::StopCrit1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StopCrit1)
{
    ui->setupUi(this);
}

StopCrit1::~StopCrit1()
{
    delete ui;
}
void StopCrit1::setv(double value){
    v=value;
}
double StopCrit1::getv(){
   return v;
}

void StopCrit1::on_buttonBox_accepted()
{
     setv(ui->doubleSpinBox->value());
}

