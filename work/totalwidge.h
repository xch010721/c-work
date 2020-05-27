#ifndef TOTALWIDGE_H
#define TOTALWIDGE_H

#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include "c_count.h"

namespace Ui {
class totalwidge;
}

class totalwidge : public QWidget
{
    Q_OBJECT

public:
    explicit totalwidge(QWidget *parent = 0);
    ~totalwidge();
    double getpay();
    double getrental();
    double getinterest();
    double getreduce();

signals:
    void changemain();
    void changemix();
    void startcout();

private slots:
    void on_pBot3_clicked();

    void on_box2_currentIndexChanged(const QString &arg1);

    void on_box1_currentIndexChanged(const QString &arg1);

    void on_pBot1_released();

private:
    Ui::totalwidge *ui;
    QButtonGroup *rBot1;
    c_count a;
    int temp;
    double to,month,in;
    double pay,ren,inte,re;

};

#endif // TOTALWIDGE_H
