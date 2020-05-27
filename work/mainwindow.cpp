#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("简易房贷计算器");
    QDoubleValidator *Dv1=new QDoubleValidator;
    Dv1->setRange(0,1000000,2);
    QDoubleValidator *Dv2=new QDoubleValidator;
    Dv2->setRange(0,1000);
    QDoubleValidator *Dv3=new QDoubleValidator;
    Dv3->setRange(0,10,2);
    QDoubleValidator *Dv4=new QDoubleValidator;
    Dv4->setRange(0,100,2);
    QDoubleValidator *Dv5=new QDoubleValidator;
    Dv5->setRange(0,100);
    ui->line1->setValidator(Dv1);
    ui->line1->setPlaceholderText("仅限输入0-1000000");
    ui->line2->setValidator(Dv2);
    ui->line2->setPlaceholderText("仅限输入0-1000的整数");
    ui->line3->setValidator(Dv3);
    ui->line3->setPlaceholderText("仅限输入0-10");
    ui->line4->setValidator(Dv5);
    ui->line4->setPlaceholderText("仅限输入0-100的整数");
    ui->line5->setValidator(Dv4);
    ui->line5->setPlaceholderText("仅限输入0-100");
    connect(&mixq,&mix::changemain,this,&MainWindow::dealmix);
    connect(&mixq,&mix::startcout,this,&MainWindow::startcout_mix);
    connect(&tot,&totalwidge::changemain,this,&MainWindow::dealtot);
    connect(&tot,&totalwidge::changemix,this,&MainWindow::changemix);
    connect(&tot,&totalwidge::startcout,this,&MainWindow::startcout_tot);
    connect(&coutq,&coutqt::changemain,this,&MainWindow::dealcout);
    rBot1=new QButtonGroup(this);
    rBot1->addButton(ui->rBot1,0);
    rBot1->addButton(ui->rBot2,1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pBot3_clicked()
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

void MainWindow::on_box1_currentIndexChanged(const QString &arg1)
{
        this->hide();
        mixq.show();
}

void MainWindow::dealmix()
{
    this->show();
    mixq.hide();
}

void MainWindow::changemix()
{
    tot.hide();
    mixq.show();
}

void MainWindow::startcout_mix()
{
    pay=mixq.getpay();
    ren=mixq.getrental();
    in=mixq.getinterest();
    re=mixq.getreduce();
    coutq.cinnumber(pay,ren,in,re);
    coutq.addnumber();
    mixq.hide();
    coutq.show();
}
void MainWindow::on_box2_currentIndexChanged(const QString &arg1)
{
    this->hide();
    tot.show();
}

void MainWindow::dealtot()
{
    this->show();
    tot.hide();
}

void MainWindow::startcout_tot()
{
    pay=tot.getpay();
    ren=tot.getrental();
    in=tot.getinterest();
    re=tot.getreduce();
    coutq.cinnumber(pay,ren,in,re);
    coutq.addnumber();
    tot.hide();
    coutq.show();
}
void MainWindow::on_pBot1_released()
{
    temp=rBot1->checkedId();
    cost=ui->line1->text().toDouble();
    area=ui->line2->text().toDouble();
    per=ui->line3->text().toDouble();
    month=ui->line4->text().toDouble()*12;
    interest=ui->line5->text().toDouble();
    a.areacount(temp,cost,area,per,month,interest);
    pay=a.getpay();
    ren=a.getrental();
    in=a.getinterest();
    re=a.getreduce();
    coutq.cinnumber(pay,ren,in,re);
    coutq.addnumber();
    this->hide();
    coutq.show();
}

void MainWindow::dealcout()
{
    this->show();
    coutq.hide();
}
