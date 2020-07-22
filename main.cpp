#include <QApplication>
#include "mainwindow.h"
#include "loginform.h"

int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    MainWindow *w = new MainWindow();
    w->setWindowTitle("工资管理系统");//设置窗体标题

    LoginForm login;
    if (login.exec() == QDialog::Accepted)//调用login.exec()，阻塞主控制流，直到完成返回，继续执行主控制流
    {
       w->show();
       return app.exec();
    }
    else return 0;
}
