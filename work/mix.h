#ifndef MIX_H
#define MIX_H

#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include "c_count.h"

namespace Ui {
class mix;
}

class mix : public QWidget
{
    Q_OBJECT

public:
    explicit mix(QWidget *parent = 0);
    ~mix();
    double getpay();
    double getrental();
    double getinterest();
    double getreduce();


signals:
    void changemain();

    void startcout();

private slots:
    void on_pBot3_clicked();

    void on_box1_currentIndexChanged(const QString &arg1);

    void on_pBot1_released();

private:
    Ui::mix *ui;
    QButtonGroup *rBot1;
    c_count a;
    int temp;
    double cost1,cost2,in1,in2,month;
    double pay,ren,in,re;
};

#endif // MIX_H
