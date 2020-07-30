#ifndef SALARY_DETAIL_H
#define SALARY_DETAIL_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSqlRecord>
#include <QTableWidget>
class salarydetail : public QDialog
{
    Q_OBJECT //使用信号与槽需要的宏
public:
    explicit salarydetail(QSqlRecord& record,QDialog *parent = 0);  //explicit 防止歧义

signals:


private:
    QPushButton *loginBtn;       //确定按钮
    QPushButton *exitBtn;        //退出按钮
    QTableWidget *detail;
};

#endif 
