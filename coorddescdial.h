#ifndef COORDDESCDIAL_H
#define COORDDESCDIAL_H

#include <QDialog>

namespace Ui {
class CoordDescDial;
}

class CoordDescDial : public QDialog
{
    Q_OBJECT

public:
    explicit CoordDescDial(QWidget *parent = nullptr);
    ~CoordDescDial();
    double getLen();
    double getAccuracy();
private slots:
    void setAccuracy(double);
    void setLen(double);
    void on_buttonBox_accepted();

private:
    Ui::CoordDescDial *ui;
    double accuracy;
    double len;
};

#endif // COORDDESCDIAL_H
