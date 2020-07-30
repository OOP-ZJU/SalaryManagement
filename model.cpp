#include "model.h"
using namespace std;
inline float after_tax(float salary)
{
    float tax;
    if(salary<36000)
        tax=salary*0.03f;
    else if(salary<144000)
        tax=(salary-36000)*0.1f+2520;
    else if(salary<300000)
        tax=(salary-144000)*0.2f+16920;
    else if(salary<420000)
        tax=(salary-144000)*0.25f+31920;
    else if(salary<660000)
        tax=(salary-144000)*0.3f+52920;
    else if(salary<960000)
        tax=(salary-144000)*0.35f+85920;
    else tax=(salary-960000)*0.45f+181920;
    return salary-tax;
}
float worker::get_net_salary_total(){
    return after_tax(wage+overtime+bonus);
}
float management::get_net_salary_total(){
    return after_tax(wage+bonus+motivation);
}
float tech::get_net_salary_total(){
    return after_tax(wage+bonus+skill+project_budget);
}
float sales::get_net_salary_total(){
    return  after_tax(wage+bonus+sales_compensation);
}

employee::employee(QSqlRecord &record)
    :sex(record.value("sex").toUInt()),name(record.value("name").toString()),dept(record.value("department").toString()),phone(record.value("phone number").toString()),wage(record.value("salary").toFloat()){

}
void management::print_salary_detail(QTableWidget &display)
{
    QString tmp[]={"name","wage","bonus","motivation","total(after tax)"};

    float w[]={wage,bonus,motivation,get_net_salary_total()};
    if(auto p=display.item(0,0))p->setData(0,tmp[0]);
        else display.setItem(0,0,new QTableWidgetItem(tmp[0]));
    if(auto p=display.item(0,1))p->setData(0,name);
        else display.setItem(0,1,new QTableWidgetItem(name));
    for(int j=1;j<5;j++)
    {
        if(auto p=display.item(j,0))p->setData(0,tmp[j]);
            else display.setItem(j,0,new QTableWidgetItem(tmp[j]));
        if(auto p=display.item(j,1))p->setData(0,w[j-1]);
            else display.setItem(j,1,new QTableWidgetItem(QString::number(w[j-1])));
    }
}
void tech::print_salary_detail(QTableWidget &display){
    QString tmp[]={"name","wage","bonus","skill","project_budget","total(after tax)"};
    float w[]={wage,bonus,skill,project_budget,get_net_salary_total()};
    if(auto p=display.item(0,0))p->setData(0,tmp[0]);
        else display.setItem(0,0,new QTableWidgetItem(tmp[0]));
    if(auto p=display.item(0,1))p->setData(0,name);
        else display.setItem(0,1,new QTableWidgetItem(name));
    for(int j=1;j<5;j++)
    {
        if(auto p=display.item(j,0))p->setData(0,tmp[j]);
            else display.setItem(j,0,new QTableWidgetItem(tmp[j]));
        if(auto p=display.item(j,1))p->setData(0,w[j-1]);
            else display.setItem(j,1,new QTableWidgetItem(QString::number(w[j-1])));
    }

}
void sales::print_salary_detail(QTableWidget &display){    
    QString tmp[]={"name","wage","bonus","sales_compensation","total(after tax)"};
    float w[]={wage,bonus,sales_compensation,get_net_salary_total()};
    if(auto p=display.item(0,0))p->setData(0,tmp[0]);
        else display.setItem(0,0,new QTableWidgetItem(tmp[0]));
    if(auto p=display.item(0,1))p->setData(0,name);
        else display.setItem(0,1,new QTableWidgetItem(name));
    for(int j=1;j<5;j++)
    {
        if(auto p=display.item(j,0))p->setData(0,tmp[j]);
            else display.setItem(j,0,new QTableWidgetItem(tmp[j]));
        if(auto p=display.item(j,1))p->setData(0,w[j-1]);
            else display.setItem(j,1,new QTableWidgetItem(QString::number(w[j-1])));
    }
}
void worker::print_salary_detail(QTableWidget &display){  
    QString tmp[]={"name","wage","overtime","bonus","total(after tax)"};
    float w[]={wage,overtime,bonus,get_net_salary_total()};
    if(auto p=display.item(0,0))p->setData(0,tmp[0]);
        else display.setItem(0,0,new QTableWidgetItem(tmp[0]));
    if(auto p=display.item(0,1))p->setData(0,name);
        else display.setItem(0,1,new QTableWidgetItem(name));
    for(int j=1;j<5;j++)
    {
        if(auto p=display.item(j,0))p->setData(0,tmp[j]);
            else display.setItem(j,0,new QTableWidgetItem(tmp[j]));
        if(auto p=display.item(j,1))p->setData(0,w[j-1]);
            else display.setItem(j,1,new QTableWidgetItem(QString::number(w[j-1])));
    }
}

management::management(QSqlRecord &record):employee(record),bonus(0),motivation(0){}
tech::tech(QSqlRecord &record):employee(record),skill(0),bonus(0),project_budget(0){}
sales::sales(QSqlRecord &record):employee(record),sales_compensation(0),bonus(0){}
worker::worker(QSqlRecord &record):employee(record),bonus(0),overtime(0){}
#ifdef _DEBUG_0
int main(void){
    worker z3();
    
    return 0;
}
#endif
