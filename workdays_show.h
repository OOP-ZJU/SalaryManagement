#ifndef WORKDAYS_SHOW_H
#define WORKDAYS_SHOW_H

#include <QDialog>
#include "QtSql"
#include "QSqlTableModel"
#include "QTableView"

namespace Ui {
class workdays_show;
}

class workdays_show : public QDialog
{
    Q_OBJECT

public:
    explicit workdays_show(QWidget *parent = nullptr);
    ~workdays_show();

private:
    void initTableView();
    QSqlTableModel *model;
    Ui::workdays_show *ui;
};

#endif // WORKDAYS_SHOW_H
