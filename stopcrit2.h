#ifndef STOPCRIT2_H
#define STOPCRIT2_H

#include <QDialog>

namespace Ui {
class StopCrit2;
}

class StopCrit2 : public QDialog
{
    Q_OBJECT

public:
    explicit StopCrit2(QWidget *parent = nullptr);
    ~StopCrit2();
    void setv(double);
    double getv();
private slots:
    void on_buttonBox_accepted();

private:
    Ui::StopCrit2 *ui;
    double v;
};

#endif // STOPCRIT2_H
