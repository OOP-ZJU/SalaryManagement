#include "salarydetail.h"
#include <QMessageBox>
#include <QHeaderView>
#include "model.h"
salarydetail::salarydetail(QSqlRecord& record,QDialog *parent) :
    QDialog(parent)
{
    worker emp1(record);
    //设置窗体标题
    this->setWindowTitle(tr("工资明细"));
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
    detail->move(70,30);
    emp1.print_salary_detail(*detail);

}

