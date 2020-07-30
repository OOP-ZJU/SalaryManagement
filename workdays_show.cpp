#include "workdays_show.h"
#include "ui_workdays_show.h"

workdays_show::workdays_show(QWidget *parent) :
    QDialog(parent),model(NULL),
    ui(new Ui::workdays_show)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("显示员工考勤情况"));
    initTableView();
}

workdays_show::~workdays_show()
{
    delete ui;
}

void workdays_show::initTableView()
{
    // 数据模型
    if(NULL == model)
        model = new QSqlTableModel;
    model->setTable("salary");
    // 按编号排序
    model->setSort(0, Qt::AscendingOrder);
    model->setHeaderData(0,Qt::Horizontal,tr("id"));
    model->setHeaderData(1,Qt::Horizontal,tr("name"));
    model->setHeaderData(2,Qt::Horizontal,tr("workdays"));
    model->removeColumns(2,3);
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
}
