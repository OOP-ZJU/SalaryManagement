#include "additionaldays_show.h"
#include "ui_additionaldays_show.h"

Additionaldays_show::Additionaldays_show(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Additionaldays_show)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("显示加班津贴情况"));
}

Additionaldays_show::~Additionaldays_show()
{
    delete ui;
}
