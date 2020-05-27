#include "coutqt.h"
#include "ui_coutqt.h"

coutqt::coutqt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::coutqt)
{
    ui->setupUi(this);
    this->setWindowTitle("计算结果");
    ui->line1->setReadOnly(true);
    ui->line2->setReadOnly(true);
    ui->line3->setReadOnly(true);
    ui->line4->setReadOnly(true);

}

coutqt::~coutqt()
{
    delete ui;
}

void coutqt::on_pBot2_released()
{
    emit changemain();
}

void coutqt::cinnumber(double a, double b, double c, double d)
{
    m_pay=a;
    rental=b;
    interest=c;
    reduce=d;
}

void coutqt::addnumber()
{
    QString str_interest,str_rantal, str_pay,str_reduce;
    if(interest<0||m_pay<0||rental<0||reduce<0)
    {
        str_interest="error";
        str_rantal="error";
        str_pay="error";
        str_reduce="error";
    }
    else
    {
        str_interest=QString::number(interest,'.',2);
        str_pay=QString::number(m_pay,'.',2);
        str_rantal=QString::number(rental,'.',2);
        if(reduce==0)
        {
            str_reduce="无递减";
        }
        else
        {
        str_reduce=QString::number(reduce,'.',2);
        }
    }
    ui->line1->setText(str_pay);
    ui->line2->setText(str_rantal);
    ui->line3->setText(str_interest);
    ui->line4->setText(str_reduce);
}
