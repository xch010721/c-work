#include "totalwidge.h"
#include "ui_totalwidge.h"

totalwidge::totalwidge(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::totalwidge)
{
    ui->setupUi(this);
    this->setWindowTitle("简易房贷计算器");
    QDoubleValidator *Dv1=new QDoubleValidator;
    Dv1->setRange(0,100000000,2);
    QDoubleValidator *Dv2=new QDoubleValidator;
    Dv2->setRange(0,100);
    QDoubleValidator *Dv3=new QDoubleValidator;
    Dv3->setRange(0,100,2);
    ui->line1->setValidator(Dv1);
    ui->line1->setPlaceholderText("仅限输入0-100000000");
    ui->line2->setValidator(Dv2);
    ui->line1->setPlaceholderText("仅限输入0-100的年数");
    ui->line3->setValidator(Dv3);
    ui->line1->setPlaceholderText("仅限输入0-100");
    rBot1=new QButtonGroup(this);
    rBot1->addButton(ui->rBot1,0);
    rBot1->addButton(ui->rBot2,1);
}

totalwidge::~totalwidge()
{
    delete ui;
}

void totalwidge::on_pBot3_clicked()
{
    QMessageBox::StandardButton btn;
    btn = QMessageBox::question(this, "提示", "确实要删除吗?", QMessageBox::Yes|QMessageBox::No);
    if(btn == QMessageBox::Yes)
    {
        ui->line1->clear();
        ui->line2->clear();
        ui->line3->clear();
    }
    else
    {
        return;
    }
}

void totalwidge::on_box2_currentIndexChanged(const QString &arg1)
{
    emit changemain();
}

void totalwidge::on_box1_currentIndexChanged(const QString &arg1)
{
    emit changemix();
}

void totalwidge::on_pBot1_released()
{
    temp=rBot1->checkedId();
    to=ui->line1->text().toDouble();
    month=ui->line2->text().toDouble()*12;
    in=ui->line3->text().toDouble();
    a.totcount(temp,to,month,in);
    pay=a.getpay();
    ren=a.getrental();
    inte=a.getinterest();
    re=a.getreduce();
    emit startcout();
}

double totalwidge::getinterest()
{
    return inte;
}

double totalwidge::getpay()
{
    return pay;
}

double totalwidge::getreduce()
{
    return re;
}

double totalwidge::getrental()
{
    return ren;
}
