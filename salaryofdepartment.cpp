#include "salaryofdepartment.h"
#include "ui_salaryofdepartment.h"

Salaryofdepartment::Salaryofdepartment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Salaryofdepartment)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("显示部门工资"));
}

Salaryofdepartment::~Salaryofdepartment()
{
    delete ui;
}
