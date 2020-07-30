#include "salarydetail.h"
#include <QMessageBox>
#include <QHeaderView>
#include "model.h"
#include "databaseserver.h"
salarydetail::salarydetail(QSqlRecord& record,MainWindow *parent) :
    QDialog(parent)
{
    employee* emp1=NULL;
    auto job=record.value("job").toString();
    if(job=="Manager")emp1=new management(record);
    else if(job=="Worker")emp1=new worker(record);
    else if(job=="Tech")emp1=new tech(record);
    else if(job=="Sales")emp1=new sales(record);
    //设置窗体标题

    this->setWindowTitle(record.value("name").toString()+"工资明细");
    this->resize(QSize(400,300));

    //设置字体大小
    QFont ft;
    ft.setPointSize(12);

    detail=new QTableWidget(this);
    detail->resize(252,188);
    detail->setRowCount(5);
    detail->setColumnCount(2);
    detail->verticalHeader()->setVisible(false);
    detail->horizontalHeader()->setVisible(false);
    detail->horizontalHeader()->setStretchLastSection(true);
    detail->verticalHeader()->setStretchLastSection(true);
    detail->move(70,30);
    if(emp1){


        int extra=DatabaseServer::getExtraWork(emp1->id);
        int days=DatabaseServer::getAttendance(emp1->id);
        float ot=count_overtime(extra,emp1->wage);
        if(job=="Worker")dynamic_cast<worker*>(emp1)->overtime=ot;
        emp1->bonus=count_bonus(days,emp1->wage);
        emp1->print_salary_detail(*detail);
        //DatabaseServer::setSalaryTaxed(emp1->id,QString::number(emp1->taxed,'f',2));
        //parent->model->select();
    }


}

