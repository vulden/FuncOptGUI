#ifndef AREADIALOG_H
#define AREADIALOG_H

#include <QDialog>

namespace Ui {
class areadialog;
}

class areadialog : public QDialog
{
    Q_OBJECT

public:
    explicit areadialog(QWidget *parent = nullptr);
    ~areadialog();
    double x1;
    double y1;
    double x2;
    double y2;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::areadialog *ui;
};

#endif // AREADIALOG_H
