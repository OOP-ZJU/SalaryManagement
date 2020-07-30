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
    if(DBS.connectDB()){
        DBS.createDB();
        DBS.initDB();
        // 初始化 tableView
        initTableView();
      }
//    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
//    setFixedSize(this->width(), this->height());
}

MainWindow::~MainWindow(){}

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

    // connect(view->selectionModel(),
    //         &QItemSelectionModel::currentRowChanged,
    //         this,
    //         &MainWindow::setTitle
    //         );
   connect(view,&QTableView::doubleClicked,this,&MainWindow::on_table_clicked);
}
void MainWindow::on_table_clicked(const QModelIndex &index){
    int row=index.row();

    auto record=model->record(row);
    salarydetail *detailwindow=new salarydetail(record,NULL);

    detailwindow->show();
    //this->setWindowTitle(QString::number(index.row()));
}
void MainWindow::on_action_triggered()
{
    dlgKinds = new kinds(this);
    dlgKinds->exec();
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
    QAbstractItemModel *model = ui->tableView->model ();
    QModelIndex idIndex = model->index(row,0);
    QModelIndex nameIndex = model->index(row,1);
    QVariant idData = model->data(idIndex);
    QVariant nameData = model->data(nameIndex);
    if(QMessageBox::question(this,
                             tr("Info"),
                             tr("Are you sure to delete ")+nameData.toString()+" ?",
                             QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
         /*deleteBook(idData.toString());*/ /*此处为在数据库删除员工信息函数，之前已经选中了删除的信息行数*/
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

bool MainWindow::insertPeople(const QString name, const QString id, const QString sex, const QString phonenum, const QString department, const QString job, const QString salary) {

    // 这里写插入sql语句
    //QSqlQuery query;
    //QString sql("INSERT INTO tb_book VALUES(null,'"+name.trimmed()+"',"+number.trimmed()+")");
    //qDebug() << sql;

    //"1"填执行成功条件
    if(1){
        // 执行成功
        QMessageBox::information(this,tr("Info"),tr("Insert Success"),QMessageBox::Yes);
      }else{
        // 执行失败
        QMessageBox::information(this,tr("Info"),tr("Invalid input"),QMessageBox::Yes);
        // qDebug() << query.lastError().text();
      }

    // 刷新 tableView
    initTableView();
    return true;
}



// 此为参考用删除函数
//bool MainWindow::deleteBook(const QString id){
//  // 删除图书语句
//  QSqlQuery query;
//  QString sql("DELETE from tb_book where id = "+id);
//  qDebug() << sql;
//  if(query.exec(sql)){
//      // 执行成功
//      QMessageBox::information(this,tr("Info"),tr("Delete Success"),QMessageBox::Yes);
//    }else{
//      // 执行失败
//      QString e = query.lastError().text();
//      if(e.contains("denied")){
//          // 没有删除的权限
//          QMessageBox::information(this,tr("Info"),tr("You don't have permission for deletion"),QMessageBox::Yes);
//        }else{
//          // 发生了错误
//          QMessageBox::information(this,tr("Info"),tr("Error occured"),QMessageBox::Yes);
//        }

//      qDebug() << e;
//    }

//  // 刷新 tableView
//  initTableView();
//  return true;
//}

bool MainWindow::changePeople(const QString name, const QString id, const QString sex, const QString phonenum, const QString department, const QString job) {
    // 这里写插入sql语句
    //QSqlQuery query;
    //QString sql("INSERT INTO tb_book VALUES(null,'"+name.trimmed()+"',"+number.trimmed()+")");
    //qDebug() << sql;

    //"1"填执行成功条件
    if(0){
        // 执行成功
        QMessageBox::information(this,tr("Info"),tr("Change Success"),QMessageBox::Yes);
      }else{
        // 执行失败
        QMessageBox::information(this,tr("Info"),tr("Invalid input"),QMessageBox::Yes);
        // qDebug() << query.lastError().text();
      }

    // 刷新 tableView
    initTableView();
    return true;
}

bool MainWindow::setWorkDays(const QString id, const QString days) {
    // 这里写插入sql语句
    //QSqlQuery query;
    //QString sql("INSERT INTO tb_book VALUES(null,'"+name.trimmed()+"',"+number.trimmed()+")");
    //qDebug() << sql;

    //"1"填执行成功条件
    if(0){
        // 执行成功
        QMessageBox::information(this,tr("Info"),tr("Set Success"),QMessageBox::Yes);
      }else{
        // 执行失败
        QMessageBox::information(this,tr("Info"),tr("Invalid input"),QMessageBox::Yes);
        // qDebug() << query.lastError().text();
      }

    // 刷新 tableView
    initTableView();
    return true;
}

bool MainWindow::setAdditionalDays(const QString id, const QString days) {
    // 这里写插入sql语句
    //QSqlQuery query;
    //QString sql("INSERT INTO tb_book VALUES(null,'"+name.trimmed()+"',"+number.trimmed()+")");
    //qDebug() << sql;

    //"1"填执行成功条件
    if(0){
        // 执行成功
        QMessageBox::information(this,tr("Info"),tr("Set Success"),QMessageBox::Yes);
      }else{
        // 执行失败
        QMessageBox::information(this,tr("Info"),tr("Invalid input"),QMessageBox::Yes);
        // qDebug() << query.lastError().text();
      }

    // 刷新 tableView
    initTableView();
    return true;
}

