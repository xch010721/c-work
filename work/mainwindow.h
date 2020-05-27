#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QString>
#include <QMessageBox>
#include "totalwidge.h"
#include "mix.h"
#include "coutqt.h"
#include "c_count.h"
#include <iostream>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void dealmix();
    void dealtot();
    void dealcout();
    void changemix();
    void startcout_mix();
    void startcout_tot();

private slots:
    void on_pBot3_clicked();

    void on_box1_currentIndexChanged(const QString &arg1);

    void on_box2_currentIndexChanged(const QString &arg1);

    void on_pBot1_released();


private:
    Ui::MainWindow *ui;
    totalwidge tot;
    mix mixq;
    coutqt coutq;
    c_count a;
    QButtonGroup *rBot1;
    int temp;
    double cost,area,per,month,interest;
    double pay,ren,in,re;


};

#endif // MAINWINDOW_H
