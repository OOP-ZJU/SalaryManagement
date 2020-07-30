#include "salarydetail.h"
#include <QMessageBox>
#include <QHeaderView>
#include "model.h"
salarydetail::salarydetail(QSqlRecord& record,QDialog *parent) :
    QDialog(parent)
{
    employee* emp1=NULL;
    auto job=record.value("job").toString();
    if(job=="Manager")emp1=new management(record);
    else if(job=="Worker")emp1=new worker(record);
    else if(job=="Tech")emp1=new tech(record);
    else if(job=="Sales")emp1=new sales(record);
    //设置窗体标题
    this->setWindowTitle(tr("工资明细"));
    this->resize(QSize(400,300));

    //设置字体大小
    QFont ft;
    ft.setPointSize(12);

    detail=new QTableWidget(this);
    detail->setRowCount(7);
    detail->resize(252,150);
    detail->setColumnCount(2);
    detail->verticalHeader()->setVisible(false);
    detail->horizontalHeader()->setVisible(false);
    detail->move(70,30);



    if(emp1)emp1->print_salary_detail(*detail);

}

