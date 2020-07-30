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
    QString id,name,phone,dept;
    float wage;
    private:
    public:
    employee(QString &id,QString &name,QString &dept,char sex,QString &phone,float wage=0)
        :id(id),name(name),dept(dept),wage(wage),phone(phone),sex(sex){
    }
    employee(QSqlRecord &record);
    virtual void print_salary_detail(QTableWidget &display)=0;
    virtual float get_net_salary_total()=0;
    //virtual float salary_taxed();
};
class management:public employee{
    public:
    management(QString &id,QString &name,QString &dept,char sex,QString &phone,float wage=0)
        :employee(id,name,dept,sex,phone,wage),bonus(0.0f),motivation(0.0f){
        
    }
    management(QSqlRecord &record);
    float get_net_salary_total();
    virtual void print_salary_detail(QTableWidget &display);
    //virtual float salary_taxed();
    private:
    float bonus,motivation;
};
class tech:public employee{
    public:
    tech(QString &id,QString &name,QString &dept,char sex,QString &phone,float wage=0)
        :employee(id,name,dept,sex,phone,wage){}
    float get_net_salary_total();
    virtual void print_salary_detail(QTableWidget &display);
    //virtual float salary_taxed();
    tech(QSqlRecord &record);
    private:
    float skill,bonus,project_budget;
};
class sales:public employee{
    public:
    sales(QString &id,QString &name,QString &dept,char sex,QString &phone,float wage=0)
        :employee(id,name,dept,sex,phone,wage){}
    float get_net_salary_total();
    virtual void print_salary_detail(QTableWidget &display);
    //virtual float salary_taxed();
    sales(QSqlRecord &record);
    private:
    float bonus,sales_compensation;

};
class worker:public employee{
    public:
    worker(QSqlRecord &record);
    float get_net_salary_total();
    virtual void print_salary_detail(QTableWidget &display);
    //virtual float salary_taxed();
    worker(QString &id,QString &name,QString &dept,char sex,QString &phone,float wage=0)
        :employee(id,name,dept,sex,phone,wage){}
    private:
    float bonus,overtime;
};
#endif
