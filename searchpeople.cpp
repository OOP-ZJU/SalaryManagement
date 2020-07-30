#include "searchpeople.h"
#include "ui_searchpeople.h"

searchPeople::searchPeople(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchPeople)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("搜索"));
}

searchPeople::~searchPeople()
{
    delete ui;
}

void searchPeople::accept(){
  this->hide();
  emit searchpeople(ui->textName->toPlainText(),ui->textId->toPlainText(),ui->textPhonenum->toPlainText(),ui->textDepartment->toPlainText(),ui->textJob->toPlainText());
}
