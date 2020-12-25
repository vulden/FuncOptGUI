#include "areadialog.h"
#include "ui_areadialog.h"

areadialog::areadialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::areadialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

areadialog::~areadialog()
{
    delete ui;
}


void areadialog::on_buttonBox_accepted()
{
    x1=ui->doubleSpinBox->value();
    y1=ui->doubleSpinBox_2 ->value();
    x2=ui->doubleSpinBox_3 ->value();
    y2=ui->doubleSpinBox_4 ->value();
}
