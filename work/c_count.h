#ifndef COUNT_H
#define COUNT_H

#include <cmath>
#include <iostream>
using namespace std;

class c_count
{
public:
    c_count();
    void areacount(int tep,double a,double b,double c,double d,double e);
    void mixcount(int tep,double a,double b,double c,double d,double e);
    void totcount(int tep,double a,double b,double c);
    double getpay();
    double getrental();
    double getinterest();
    double getreduce();


private:
    double m_pay,rental,interest,reduce;
};

#endif // COUNT_H
