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

public slots:
    void login();//点击登录按钮是执行的槽函数
private:
    QLabel *userNameLbl;         //"用户名"标签
    QLabel *pwdLbl;              //"密码"标签
    QLineEdit *userNameLEd;      //用户名编辑行
    QLineEdit *pwdLEd;           //密码编辑行
    QPushButton *loginBtn;       //登录按钮
    QPushButton *exitBtn;        //退出按钮
    QTableWidget *detail;
};

#endif 
