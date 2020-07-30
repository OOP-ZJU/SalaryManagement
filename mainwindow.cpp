#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "salarydetail.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),model(NULL),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    if(DBS.connectDB())
    {
        DBS.createDB();
        DBS.initDB();
        // 初始化 tableView
        initTableView();
    }

//    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
//    setFixedSize(this->width(), this->height());
}

MainWindow::~MainWindow()
{
    if(NULL != model)
        delete model;
}

/**
 * 连接数据库
 * 我用的是sql server，其他的在基础上改一改就行
 * @brief connect
 * @return
 */

bool MainWindow::connectDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QApplication::applicationDirPath()+"/scooters.dat");    //如果本目录下没有该文件,则会在本目录下生成,否则连接该文件
    if (!db.open()) {
        QMessageBox::warning(0, QObject::tr("Database Error"),
                             db.lastError().text());
        return false;
    }
    return true;
}

/**
 * @brief MainWindow::initTableView
 * 从图书管理系统扒过来的，直接把数据库按列塞进去改名字就行
 */

void MainWindow::initTableView() {
    // 数据模型
    if(NULL == model)
        model = new QSqlTableModel;
    model->setTable("information");
    // 按编号排序
    model->setSort(0, Qt::AscendingOrder);
    model->setHeaderData(0,Qt::Horizontal,tr("id"));
    model->setHeaderData(1,Qt::Horizontal,tr("name"));
    model->setHeaderData(2,Qt::Horizontal,tr("sex"));
    model->setHeaderData(3,Qt::Horizontal,tr("phone number"));
    model->setHeaderData(4,Qt::Horizontal,tr("department"));
    model->setHeaderData(5,Qt::Horizontal,tr("job"));
    model->setHeaderData(6,Qt::Horizontal,tr("salary"));
    model->select();
    // 表格视图
    QTableView *view = ui->tableView;
    view->setModel(model);
//    view->setColumnWidth(1,500);

    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    //  view->setColumnHidden(0, true);
    //  view->resizeColumnsToContents();
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->show();
    // 表头
    QHeaderView *header = view->horizontalHeader();
    header->setStretchLastSection(true);
    connect(view,&QTableView::doubleClicked,this,&MainWindow::on_table_clicked);
}
void MainWindow::on_table_clicked(const QModelIndex &index){
    int row=index.row();

    auto record=model->record(row);
    salarydetail *detailwindow=new salarydetail(record,this);

    detailwindow->show();
    //this->setWindowTitle(QString::number(index.row()));
}
void MainWindow::on_action_triggered()
{
    dlgKinds = new kinds(this);
    dlgKinds->exec();
}

void MainWindow::on_action_2_triggered()
{
    dlgworkdays_show = new workdays_show(this);
    dlgworkdays_show->exec();
}

void MainWindow::on_action_3_triggered()
{
    dlgAdditionaldays_show = new Additionaldays_show(this);
    dlgAdditionaldays_show->exec();
}

void MainWindow::on_action_4_triggered()
{
    dlgSearchPeople = new searchPeople(this);
    connect(dlgSearchPeople,&searchPeople::searchpeople,this,&MainWindow::search);
    dlgSearchPeople->exec();
}


void MainWindow::on_action_5_triggered()
{
    dlgSalaryofdepartment = new Salaryofdepartment(this);
    dlgSalaryofdepartment->exec();
}

void MainWindow::on_action_7_triggered()
{
    dlgAddPeople = new addPeople(this);
    connect(dlgAddPeople,&addPeople::addpeople,this,&MainWindow::insertPeople);
    dlgAddPeople->exec();
}

void MainWindow::on_action_8_triggered()
{
    int row= ui->tableView->currentIndex().row();
    QAbstractItemModel *model = ui->tableView->model();
    QModelIndex idIndex = model->index(row,0);
    QModelIndex nameIndex = model->index(row,1);
    QVariant idData = model->data(idIndex);
    QVariant nameData = model->data(nameIndex);
    if(QMessageBox::question(this,
                             tr("Info"),
                             tr("Are you sure to delete ")+nameData.toString()+" ?",
                             QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes)
    {
        deletePeople(idData.toString()); /*此处为在数据库删除员工信息函数，之前已经选中了删除的信息行数*/
    }
}

void MainWindow::on_action_9_triggered()
{
    dlgModifyPeople = new modifyPeople(this);
    connect(dlgModifyPeople,&modifyPeople::modifypeople,this,&MainWindow::changePeople);
    dlgModifyPeople->exec();
}

void MainWindow::on_action_10_triggered()
{
    dlgWorkDays = new workDays(this);
    connect(dlgWorkDays,&workDays::setworkdays,this,&MainWindow::setWorkDays);
    dlgWorkDays->exec();
}

void MainWindow::on_action_12_triggered()
{
    dlgAdditionalDays = new additionalDays(this);
    connect(dlgAdditionalDays,&additionalDays::setadditionaldays,this,&MainWindow::setAdditionalDays);
    dlgAdditionalDays->exec();
}

bool MainWindow::insertPeople(const QString name, const QString id, const QString sex, const QString phonenum, const QString department, const QString job, const QString salary)
{
    QSqlQuery query;
    //"insert into information values('0000000001','Ylc','M','1111','Sci','Manager',11.22)"
    QString sql = tr("insert into information values('%1','%2','%3','%4','%5','%6',%7)")
                    .arg(id,10,QLatin1Char('0'))
                    .arg(name).arg(sex).arg(phonenum)
                    .arg(department).arg(job).arg(salary);

    if(query.exec(sql))
    {
        // 执行成功
        QMessageBox::information(this,tr("Info"),tr("Insert Success"),QMessageBox::Yes);
    }
    else
    {
        // 执行失败
        QMessageBox::information(this,tr("Info"),tr("Invalid input"),QMessageBox::Yes);
        qDebug() << query.lastError().text();
        return false;
    }

    sql = tr("insert into salary values('%1','%2',%3,10,0,0)")
            .arg(id,10,QLatin1Char('0'))
            .arg(name).arg(salary);
    if(!query.exec(sql))
    {
        QMessageBox::information(this,tr("Info"),tr("Invalid input"),QMessageBox::Yes);
        qDebug() << query.lastError().text();
        return false;
    }
    // 刷新 tableView
    model->select();
    return true;
}


bool MainWindow::deletePeople(const QString id)
{
    // 删除图书语句
    QSqlQuery query;
    QString sql= tr("delete from information where id = '%1'").arg(id,10,QLatin1Char('0'));
    qDebug() << sql;
    if(query.exec(sql))
    {
        // 执行成功
        QMessageBox::information(this,tr("Info"),tr("Delete Success"),QMessageBox::Yes);
    }
    else
    {
        // 执行失败
        QString e = query.lastError().text();
        if(e.contains("denied"))
        {
            // 没有删除的权限
            QMessageBox::information(this,tr("Info"),tr("You don't have permission for deletion"),QMessageBox::Yes);
        }
        else
        {
            // 发生了错误
            QMessageBox::information(this,tr("Info"),tr("Error occured"),QMessageBox::Yes);
        }
        qDebug() << e;
        return false;
    }

    // 刷新 tableView
    model->select();
    return true;
}

bool MainWindow::changePeople(const QString name, const QString id, const QString sex, const QString phonenum, const QString department, const QString job)
{
    QSqlQuery query;
//    QString sql = tr("update information set name = '%1', sex = '%2', phone_number = '%3', department = '%4', job = '%5' where id = '%6'")
//                    .arg(name).arg(sex).arg(phonenum).arg(department).arg(job)
//                    .arg(id,10,QLatin1Char('0'));
    QString sql("update information");
    bool isSet = false;
    if(!name.isEmpty())
    {
        sql += tr(" set name = '%1'").arg(name);
        isSet = true;
    }
    if(!sex.isEmpty())
    {
        sql += (isSet ? "," : " set") + tr(" sex = '%1'").arg(sex);
        isSet = true;
    }
    if(!phonenum.isEmpty())
    {
        sql += (isSet ? "," : " set") + tr(" phone_number = '%1'").arg(phonenum);
        isSet = true;
    }
    if(!department.isEmpty())
    {
        sql += (isSet ? "," : " set") + tr(" department = '%1'").arg(department);
        isSet = true;
    }
    if(!job.isEmpty())
    {
        sql += (isSet ? "," : " set") + tr(" job = '%1'").arg(job);
        isSet = true;
    }
    sql += tr(" where id = '%1'").arg(id,10,QLatin1Char('0'));
    qDebug() << sql;
    if(query.exec(sql))
    {
        // 执行成功
        QMessageBox::information(this,tr("Info"),tr("Change Success"),QMessageBox::Yes);
    }
    else
    {
        // 执行失败
        QMessageBox::information(this,tr("Info"),tr("Invalid input"),QMessageBox::Yes);
        qDebug() << query.lastError().text();
        return false;
    }

    // 刷新 tableView
    model->select();
    return true;
}

bool MainWindow::setWorkDays(const QString days, const QString id)
{
    // 这里写插入sql语句
    //QSqlQuery query;
    //QString sql("INSERT INTO tb_book VALUES(null,'"+name.trimmed()+"',"+number.trimmed()+")");
    //qDebug() << sql;
    QSqlQuery query;
    QString sql = tr("update salary set attendance = %1 where id = '%2'")
                    .arg(days)
                    .arg(id,10,QLatin1Char('0'));
    qDebug() << sql;
    if(query.exec(sql))
    {
        // 执行成功
        QMessageBox::information(this,tr("Info"),tr("Set Success"),QMessageBox::Yes);
    }
    else
    {
        // 执行失败
        QMessageBox::information(this,tr("Info"),tr("Invalid input"),QMessageBox::Yes);
        qDebug() << query.lastError().text();
        return false;
    }

    // 刷新 tableView
    model->select();
    return true;
}

bool MainWindow::setAdditionalDays(const QString days, const QString id)
{
    QSqlQuery query;
    QString sql = tr("update salary set extra_work = %1 where id = '%2'")
                    .arg(days)
                    .arg(id,10,QLatin1Char('0'));
    qDebug() << sql;
    if(query.exec(sql))
    {
        // 执行成功
        QMessageBox::information(this,tr("Info"),tr("Set Success"),QMessageBox::Yes);
    }
    else
    {
        // 执行失败
        QMessageBox::information(this,tr("Info"),tr("Invalid input"),QMessageBox::Yes);
        qDebug() << query.lastError().text();
        return false;
    }

    // 刷新 tableView
    model->select();
    return true;
}


void MainWindow::on_action_6_triggered()
{
    QSqlQuery query;
    QString sql = "select sum(salary) from information";
    if(!query.exec(sql))
    {
        qDebug() << query.lastError().text();
        return;
    }
    else
    {
        query.next();
        qDebug() << query.value(0).toString();
        QMessageBox::information(this,tr("Info"),"total salary: " + query.value(0).toString(),QMessageBox::Yes);
    }
}
bool MainWindow::search(const QString name, const QString id, const QString phonenum, const QString department, const QString job)
{
    QString filter; //查询条件
    bool isConditionExist = false;
    if(!id.isEmpty())
    {
        filter += tr("id = '%1'").arg(id,10,QLatin1Char('0'));
        isConditionExist = true;
    }
    if(!name.isEmpty())
    {
        filter += (isConditionExist ? " and " : "") + tr("name = '%1'").arg(name);
        isConditionExist = true;
    }
    if(!phonenum.isEmpty())
    {
        filter += (isConditionExist ? " and " : "") + tr("phone_number = '%1'").arg(phonenum);
        isConditionExist = true;
    }
    if(!department.isEmpty())
    {
        filter += (isConditionExist ? " and " : "") + tr("department = '%1'").arg(department);
        isConditionExist = true;
    }
    if(!job.isEmpty())
    {
        filter += (isConditionExist ? " and " : "") + tr("job = '%1'").arg(job);
        isConditionExist = true;
    }
    if(!isConditionExist)
        model->setFilter(NULL);
    else
        model->setFilter(filter);
    qDebug() << model->filter();

    // 刷新 tableView
    if(model->select())
    {
        // 执行成功
        QMessageBox::information(this,tr("Info"),tr("select Success"),QMessageBox::Yes);
    }
    else
    {
        // 执行失败
        QMessageBox::information(this,tr("Info"),tr("Invalid input"),QMessageBox::Yes);
        qDebug() << model->lastError().text();
        return false;
    }
    return true;
}
