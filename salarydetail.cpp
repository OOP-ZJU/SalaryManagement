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
    this->resize(QSize(360,500));

    //设置字体大小
    QFont ft;
    ft.setPointSize(12);

    //用户名Label
    userNameLbl = new QLabel(this);   //new一个标签对象
    userNameLbl->move(70,40);         //移动到(70,80)位置(Label左上角坐标，相对于父窗体)
    userNameLbl->setFont(ft);         //设置字体大小为12号
    userNameLbl->setText("用户名:");  //设置标签文本

    //用户名输入框
    userNameLEd = new QLineEdit(this);
    userNameLEd->move(150,40);
    userNameLEd->setPlaceholderText(record.value(0).toString());//占位符

    //密码Label
    pwdLbl = new QLabel(this);
    pwdLbl->move(50,80);
    pwdLbl->setFont(ft);
    pwdLbl->setText("Password:");

    //密码输入框
    pwdLEd = new QLineEdit(this);
    pwdLEd->move(150,80);
    pwdLEd->setPlaceholderText(record.value("salary").toString());
    pwdLEd->setEchoMode(QLineEdit::Password);//输入的密码以圆点显示

    //登录按钮
    loginBtn = new QPushButton(this);
    loginBtn->move(90,140);
    loginBtn->setText("登录");

    //退出按钮
    exitBtn = new QPushButton(this);
    exitBtn->move(180,140);
    exitBtn->setText("退出");

    detail=new QTableWidget(this);
    detail->setRowCount(7);
    detail->setColumnCount(2);
    detail->verticalHeader()->setVisible(false);
    detail->horizontalHeader()->setVisible(false);
    detail->move(60,180);

    //单击登录按钮时 执行 salarydetail::login 槽函数(自定义)；单击退出按钮时 执行 salarydetail::close 槽函数(窗体的关闭函数，不用自己写)
    connect(loginBtn,&QPushButton::clicked,this,&salarydetail::login);
    connect(exitBtn,&QPushButton::clicked,this,&salarydetail::close);

    if(emp1)emp1->print_salary_detail(*detail);

}

void salarydetail::login()
{
    //获得userNameLEd输入框的文本：userNameLEd->text()；
    //trimmed()去掉前后空格
    //tr()函数，防止设置中文时乱码
    if(userNameLEd->text().trimmed() == tr("ylc") && pwdLEd->text() == tr("123"))
    {
       accept();//关闭窗体，并设置返回值为Accepted
    }
    else
    {                              //标题              内容                OK按钮
       QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);

    // 清空输入框内容
       userNameLEd->clear();
       pwdLEd->clear();

       //光标定位
       userNameLEd->setFocus();
    }
}
