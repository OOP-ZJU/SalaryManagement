#include "workdays_show.h"
#include "ui_workdays_show.h"

workdays_show::workdays_show(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::workdays_show)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("显示员工考勤情况"));
}

workdays_show::~workdays_show()
{
    delete ui;
}
