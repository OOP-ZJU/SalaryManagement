#ifndef WORKDAYS_H
#define WORKDAYS_H

#include <QDialog>

namespace Ui {
class workDays;
}

class workDays : public QDialog
{
    Q_OBJECT

public:
    explicit workDays(QWidget *parent = nullptr);
    ~workDays();

    void accept();
signals:
    void setworkdays(const QString id,const QString days);
private:
    Ui::workDays *ui;
};

#endif // WORKDAYS_H
