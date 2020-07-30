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
    ui->label->setText("Manager");
    ui->label_2->setText("Tech");
    ui->label_3->setText("Sales");
    ui->label_4->setText("Worker");

    ui->label_2->setFont(ft);
    ui->label_3->setFont(ft);
    ui->label_4->setFont(ft);
    ui->label->adjustSize();
}

kinds::~kinds()
{
    delete ui;
}
