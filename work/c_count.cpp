#include "c_count.h"

c_count::c_count(){}
void c_count::areacount(int tep, double a, double b, double c, double d, double e)
{
    double p=0;
    double t1=0;
    e/=1200; c/=10;
    if(tep==0)
    {
        reduce=0;
        t1=pow(1+e,d);
        p=a*b*c;
        m_pay=p*e*t1/(t1-1);
        rental=m_pay*d;
        interest=rental-p;

    }
    else if(tep==1)
    {
        p=a*b*c;
        m_pay=(p/d)+p*e;
        reduce=p/d*e;
        interest=(d+1)*p*e/2;
        rental=interest+p;
    }
}

void c_count::mixcount(int tep, double a, double b, double c, double d, double e)
{
     b/=1200; d/=1200;
    double t1=0;
    double pay1,pay2,ren1,ren2,in1,in2,re1,re2;
    if(tep==0)
    {
        re1=re2=0;
        t1=pow(1+b,e);
        pay1=a*b*t1/(t1-1);
        ren1=pay1*e;
        in1=ren1-a;
        t1=pow(1+d,e);
        pay2=c*d*t1/(t1-1);
        ren2=pay2*e;
        in2=ren2-c;
    }
    else if(tep==1)
    {
        pay1=(a/e)+a/b;
        re1=a/e*b;
        in1=(e+1)*a*b/2;
        ren1=in1+a;
        pay2=(c/e)+c/d;
        re2=c/e*d;
        in2=(e+1)*c*d/2;
        ren2=in2+c;
    }
    m_pay=pay1+pay2;
    rental=ren1+ren2;
    interest=in1+in2;
    reduce=re1+re2;

}

void c_count::totcount(int tep, double a, double b, double c)
{
    c/=1200;
    double t;
    if(tep==0)
    {
        reduce=0;
        t=pow(1+c,b);
        m_pay=a*c*t/(t-1);
        rental=m_pay*b;
        interest=rental-a;
    }
    else if(tep==1)
    {
        m_pay=(a/b)+a*c;
        reduce=a/b*c;
        interest=(b+1)*a*c/2;
        rental=interest+a;

    }
}

double c_count::getinterest()
{
    return interest;
}

double c_count::getpay()
{
    return m_pay;
}

double c_count::getreduce()
{
    return reduce;
}

double c_count::getrental()
{
    return rental;
}
//首月月供（本金/还款月数）+本金×月利率
//每月递减 本金/还款月数×月利率
//利息 （还款月数+1）*贷款额*月利率/2
//本息和 (还款月数+1)*贷款额*月利率/2+本金
