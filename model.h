#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <QSqlRecord>
#include <QString>
#include <QVariant>
#include <QTableWidget>
class employee{
    protected:
    char sex;
    // M for male, F for female
    QString name,phone,dept;
    friend class salarydetail;
    float wage,bonus,taxed;
    private:
    public:
    QString id;
    employee(QString &id,QString &name,QString &dept,char sex,QString &phone,float wage=0,float bonus=0.0f)
        :id(id),name(name),dept(dept),wage(wage),phone(phone),sex(sex),bonus(0.0f){
    }
    employee(QSqlRecord &record);
    virtual void print_salary_detail(QTableWidget &display)=0;
    virtual float get_net_salary_total()=0;
    //virtual float salary_taxed();
};
class management:public employee{
    public:
    management(QString &id,QString &name,QString &dept,char sex,QString &phone,float wage=0,float bonus=0)
        :employee(id,name,dept,sex,phone,wage,bonus),motivation(0.0f){
        
    }
    management(QSqlRecord &record);
    float get_net_salary_total();
    virtual void print_salary_detail(QTableWidget &display);
    //virtual float salary_taxed();
    private:
    float motivation;
};
class tech:public employee{
    public:
    tech(QString &id,QString &name,QString &dept,char sex,QString &phone,float wage=0,float bonus=0)
        :employee(id,name,dept,sex,phone,wage,bonus){}
    float get_net_salary_total();
    virtual void print_salary_detail(QTableWidget &display);
    //virtual float salary_taxed();
    tech(QSqlRecord &record);
    private:
    float skill,project_budget;
};
class sales:public employee{
    public:
    sales(QString &id,QString &name,QString &dept,char sex,QString &phone,float wage=0,float bonus=0)
        :employee(id,name,dept,sex,phone,wage,bonus){}
    float get_net_salary_total();
    virtual void print_salary_detail(QTableWidget &display);
    //virtual float salary_taxed();
    sales(QSqlRecord &record);
    private:
    float sales_compensation;

};
class worker:public employee{
    public:
    worker(QSqlRecord &record);
    float get_net_salary_total();
    virtual void print_salary_detail(QTableWidget &display);
    //virtual float salary_taxed();
    worker(QString &id,QString &name,QString &dept,char sex,QString &phone,float wage=0,float bonus=0)
        :employee(id,name,dept,sex,phone,wage,bonus){}
    private:
    float overtime;
    friend class salarydetail;
};
inline float count_overtime(int additional,float wage_base){  //考勤天数；加班天数
    return wage_base*(additional*1.5f)/21.75f;
    // 1.5倍补偿
}
inline float count_bonus(int work_days,float wage_base){
    return wage_base*(work_days-21.75f)/21.75f;
    // 每月工作天数以21.75天计，超出的部分为绩效工资（可能为负）
}
#endif
