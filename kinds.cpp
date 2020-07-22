#include "kinds.h"
#include "ui_kinds.h"

kinds::kinds(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kinds)
{
    ui->setupUi(this);
}

kinds::~kinds()
{
    delete ui;
}
