#include "localsdial.h"
#include "ui_localsdial.h"

LocalSDial::LocalSDial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LocalSDial)
{
    ui->setupUi(this);
}

LocalSDial::~LocalSDial()
{
    delete ui;
}

void LocalSDial::setP(double value){
    p=value;
}
double LocalSDial::getP(){
    return p;
}
void LocalSDial::setDelta(double value){
    delta=value;
}
double LocalSDial::getDelta(){
    return delta;
}

void LocalSDial::on_buttonBox_accepted()
{
    setDelta(ui->doubleSpinBox_2->value());
    setP(ui->doubleSpinBox->value());
}
