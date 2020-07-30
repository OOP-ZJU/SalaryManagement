#include "kinds.h"
#include "ui_kinds.h"

kinds::kinds(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kinds)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("显示工种"));
}

kinds::~kinds()
{
    delete ui;
}
