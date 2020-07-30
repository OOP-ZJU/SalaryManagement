#include "searchpeople.h"
#include "ui_searchpeople.h"

searchPeople::searchPeople(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchPeople)
{
    ui->setupUi(this);
}

searchPeople::~searchPeople()
{
    delete ui;
}
