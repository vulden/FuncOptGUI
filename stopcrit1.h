#ifndef STOPCRIT1_H
#define STOPCRIT1_H

#include <QDialog>

namespace Ui {
class StopCrit1;
}

class StopCrit1 : public QDialog
{
    Q_OBJECT

public:
    explicit StopCrit1(QWidget *parent = nullptr);
    ~StopCrit1();
    void setv(double);
    double getv();
private slots:
    void on_buttonBox_accepted();

private:
    Ui::StopCrit1 *ui;
    double v;
};

#endif // STOPCRIT1_H
