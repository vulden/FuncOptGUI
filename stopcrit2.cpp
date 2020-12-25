#include "stopcrit2.h"
#include "ui_stopcrit2.h"

StopCrit2::StopCrit2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StopCrit2)
{
    ui->setupUi(this);
}

StopCrit2::~StopCrit2()
{
    delete ui;
}
void StopCrit2::setv(double value){
    v=value;
}
double StopCrit2::getv(){
   return v;
}

void StopCrit2::on_buttonBox_accepted()
{
    setv(ui->doubleSpinBox->value());
}
