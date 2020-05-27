#ifndef COUTQT_H
#define COUTQT_H

#include <QWidget>


namespace Ui {
class coutqt;
}

class coutqt : public QWidget
{
    Q_OBJECT

signals:
    void changemain();

public:
    explicit coutqt(QWidget *parent = 0);
    ~coutqt();
    void cinnumber(double a,double b,double c,double d);
    void addnumber();

private slots:
    void on_pBot2_released();

private:
    Ui::coutqt *ui;
    double m_pay,rental,interest,reduce;

};

#endif // COUTQT_H
