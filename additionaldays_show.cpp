#include "additionaldays_show.h"
#include "ui_additionaldays_show.h"

Additionaldays_show::Additionaldays_show(QWidget *parent) :
    QDialog(parent),model(NULL),
    ui(new Ui::Additionaldays_show)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("显示加班津贴情况"));
    initTableView();
}

Additionaldays_show::~Additionaldays_show()
{
    delete ui;
    if(NULL != model)
        delete model;
}

void Additionaldays_show::initTableView()
{
    // 数据模型
    if(NULL == model)
        model = new QSqlTableModel;
    model->setTable("salary");
    // 按编号排序
    model->setSort(0, Qt::AscendingOrder);
    model->setHeaderData(0,Qt::Horizontal,tr("id"));
    model->setHeaderData(1,Qt::Horizontal,tr("name"));
    model->setHeaderData(2,Qt::Horizontal,tr("extra work days"));
    model->removeColumns(2,2);
    model->removeColumn(3);
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
