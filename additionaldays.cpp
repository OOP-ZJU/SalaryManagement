#include "additionaldays.h"
#include "ui_additionaldays.h"

additionalDays::additionalDays(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::additionalDays)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("设置员工加班天数"));
}

additionalDays::~additionalDays()
{
    delete ui;
}

void additionalDays::accept(){
  this->hide();
  emit setadditionaldays(ui->textDays->toPlainText(),ui->textId->toPlainText());
}
