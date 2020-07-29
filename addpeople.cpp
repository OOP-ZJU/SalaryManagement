#include "addpeople.h"
#include "ui_addpeople.h"

addPeople::addPeople(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPeople)
{

    ui->setupUi(this);
    this->setWindowTitle(tr("添加员工信息"));
}

addPeople::~addPeople()
{
    delete ui;
}

void addPeople::accept(){
  this->hide();
  emit addpeople(ui->textName->toPlainText(),ui->textId->toPlainText(),ui->textSex->toPlainText(),ui->textPhoneNumber->toPlainText(),ui->textDepartment->toPlainText(),ui->textJob->toPlainText(),ui->textSalary->toPlainText());
}
