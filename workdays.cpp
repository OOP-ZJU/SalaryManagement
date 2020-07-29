#include "workdays.h"
#include "ui_workdays.h"

workDays::workDays(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::workDays)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("设置员工考勤天数"));
}

workDays::~workDays()
{
    delete ui;
}

void workDays::accept(){
  this->hide();
  emit setworkdays(ui->textDays->toPlainText(),ui->textId->toPlainText());
}
