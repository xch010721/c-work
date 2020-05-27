#include "mix.h"
#include "ui_mix.h"

mix::mix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mix)
{
    ui->setupUi(this);
    this->setWindowTitle("简易房贷计算器");
    QDoubleValidator *Dv1=new QDoubleValidator;
    Dv1->setRange(0,100000000,2);
    QDoubleValidator *Dv2=new QDoubleValidator;
    Dv2->setRange(0,100,2);
    QDoubleValidator *Dv3=new QDoubleValidator;
    Dv3->setRange(0,100);
    ui->line1->setValidator(Dv1);
    ui->line1->setPlaceholderText("仅限输入0-100000000");
    ui->line2->setValidator(Dv2);
    ui->line2->setPlaceholderText("仅限输入0-100");
    ui->line3->setValidator(Dv1);
    ui->line3->setPlaceholderText("仅限输入0-100000000");
    ui->line4->setValidator(Dv2);
    ui->line1->setPlaceholderText("仅限输入0-100");
    ui->line5->setValidator(Dv3);
    ui->line1->setPlaceholderText("仅限输入0-100的整数");
    rBot1=new QButtonGroup(this);
    rBot1->addButton(ui->rBot1,0);
    rBot1->addButton(ui->rBot2,1);
}

mix::~mix()
{
    delete ui;
}

void mix::on_pBot3_clicked()
{
    QMessageBox::StandardButton btn;
    btn = QMessageBox::question(this, "提示", "确实要删除吗?", QMessageBox::Yes|QMessageBox::No);
    if(btn == QMessageBox::Yes)
    {
        ui->line1->clear();
        ui->line2->clear();
        ui->line3->clear();
        ui->line4->clear();
        ui->line5->clear();
    }
    else
    {
        return;
    }
}

void mix::on_box1_currentIndexChanged(const QString &arg1)
{
    emit changemain();
}

void mix::on_pBot1_released()
{
    temp=rBot1->checkedId();
    cost1=ui->line1->text().toDouble();
    in1=ui->line2->text().toDouble();
    cost2=ui->line3->text().toDouble();
    in2=ui->line4->text().toDouble();
    month=ui->line5->text().toDouble()*12;
    a.mixcount(temp,cost1,in1,cost2,in2,month);
    pay=a.getpay();
    ren=a.getrental();
    in=a.getinterest();
    re=a.getreduce();
    emit startcout();
}

double mix::getinterest()
{
    return in;
}

double mix::getpay()
{
    return pay;
}

double mix::getreduce()
{
    return re;
}

double mix::getrental()
{
    return ren;
}
