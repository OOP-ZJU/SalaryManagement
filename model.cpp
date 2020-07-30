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

// void employee::print_salary_detail(QTableWidget &display){
//     for(int i=0;i<2;i++)
//         for(int j=0;j<4;j++){
//             if(display.item(j,i))
//             display.item(j,i)->setData(0,i);
//             else display.setItem(j,i,new QTableWidgetItem(QString::number(j)));
//         }
// }


employee::employee(QSqlRecord &record)
    :sex(record.value("sex").toUInt()),name(record.value("name").toString()),dept(record.value("department").toString()),phone(record.value("phone number").toString()),wage(record.value("salary").toFloat()){

}
void management::print_salary_detail(QTableWidget &display){
    QString tmp[]={"wage","bonus","motivation","tax","total"};
    float w[]={wage,bonus,motivation,get_net_salary_total()};
    for(int j=0;j<4;j++){
        if(auto p=display.item(j,0))p->setData(0,tmp[j]);
            else display.setItem(j,0,new QTableWidgetItem(tmp[j]));
        if(auto p=display.item(j,1))p->setData(0,w[j]);
            else display.setItem(j,1,new QTableWidgetItem(QString::number(w[j],'f',2)));
    }
}
void tech::print_salary_detail(QTableWidget &display){
    QString tmp[]={"wage","bonus","skill","project_budget","tax","total"};
    float w[]={wage,bonus,skill,project_budget,get_net_salary_total()};
    for(int j=0;j<5;j++){
        if(auto p=display.item(j,0))p->setData(0,tmp[j]);
            else display.setItem(j,0,new QTableWidgetItem(tmp[j]));
        if(auto p=display.item(j,1))p->setData(0,w[j]);
            else display.setItem(j,1,new QTableWidgetItem(QString::number(w[j],'f',2)));
    }

}
void sales::print_salary_detail(QTableWidget &display){    
    QString tmp[]={"wage","bonus","sales_compensation","tax","total"};
    float w[]={wage,bonus,sales_compensation,get_net_salary_total()};
    for(int j=0;j<4;j++){
        if(auto p=display.item(j,0))p->setData(0,tmp[j]);
            else display.setItem(j,0,new QTableWidgetItem(tmp[j]));
        if(auto p=display.item(j,1))p->setData(0,w[j]);
            else display.setItem(j,1,new QTableWidgetItem(QString::number(w[j],'f',2)));
    }
}
void worker::print_salary_detail(QTableWidget &display){  
    QString tmp[]={"wage","bonus","overtime","tax","total"};
    float w[]={wage,bonus,overtime,get_net_salary_total()};
    for(int j=0;j<4;j++){
        if(auto p=display.item(j,0))p->setData(0,tmp[j]);
            else display.setItem(j,0,new QTableWidgetItem(tmp[j]));
        if(auto p=display.item(j,1))p->setData(0,w[j]);
            else display.setItem(j,1,new QTableWidgetItem(QString::number(w[j],'f',2)));
    }
}
inline float count_overtime(int additional,float wage_base){  //考勤天数；加班天数
    return wage_base*(additional*1.5f)/21.75f;
    // 1.5倍补偿
}
inline float count_bonus(int work_days,float wage_base){
    return wage_base*(work_days-21.75f)/21.75f;
    // 每月工作天数以21.75天计，超出的部分为绩效工资（可能为负）
}
management::management(QSqlRecord &record):employee(record),motivation(5000.0f){}
tech::tech(QSqlRecord &record):employee(record),skill(5000.0f),project_budget(5000.0f){}
sales::sales(QSqlRecord &record):employee(record),sales_compensation(5000.0f){}
worker::worker(QSqlRecord &record):employee(record),overtime(0){}
#ifdef _DEBUG_0
int main(void){
    worker z3();
    
    return 0;
}
#endif
