#ifndef ADDITIONALDAYS_SHOW_H
#define ADDITIONALDAYS_SHOW_H

#include <QDialog>
#include "QtSql"
#include "QSqlTableModel"
#include "QTableView"

namespace Ui {
class Additionaldays_show;
}

class Additionaldays_show : public QDialog
{
    Q_OBJECT

public:
    explicit Additionaldays_show(QWidget *parent = nullptr);
    ~Additionaldays_show();

private:
    void initTableView();
    QSqlTableModel *model;
    Ui::Additionaldays_show *ui;
};

#endif // ADDITIONALDAYS_SHOW_H
