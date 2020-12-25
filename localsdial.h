#ifndef LOCALSDIAL_H
#define LOCALSDIAL_H

#include <QDialog>

namespace Ui {
class LocalSDial;
}

class LocalSDial : public QDialog
{
    Q_OBJECT

public:
    explicit LocalSDial(QWidget *parent = nullptr);
    ~LocalSDial();
    double getDelta();
    double getP();
private slots:
    void setP(double);
    void setDelta(double);
    void on_buttonBox_accepted();

private:
    Ui::LocalSDial *ui;
    double delta;
    double p;
};

#endif // LOCALSDIAL_H
