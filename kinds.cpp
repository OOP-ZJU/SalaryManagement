#include "kinds.h"
#include "ui_kinds.h"

kinds::kinds(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kinds)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("显示工种"));
    QFont ft;
    ft.setPointSize(12);
    ui->label->setFont(ft);
    ui->label->setText("Manager\nTech\nSales\nWorker");
    ui->label->adjustSize();
}

kinds::~kinds()
{
    delete ui;
}
