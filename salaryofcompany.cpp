#include "salaryofcompany.h"
#include "ui_salaryofcompany.h"

Salaryofcompany::Salaryofcompany(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Salaryofcompany)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("显示公司工资"));
}

Salaryofcompany::~Salaryofcompany()
{
    delete ui;
}
