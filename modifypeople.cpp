#include "modifypeople.h"
#include "ui_modifypeople.h"

modifyPeople::modifyPeople(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifyPeople)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("修改员工信息"));
}

modifyPeople::~modifyPeople()
{
    delete ui;
}

void modifyPeople::accept(){
  this->hide();
  emit modifypeople(ui->textName->toPlainText(),ui->textId->toPlainText(),ui->textSex->toPlainText(),ui->textPhonenum->toPlainText(),ui->textDepartment->toPlainText(),ui->textJob->toPlainText());
}
