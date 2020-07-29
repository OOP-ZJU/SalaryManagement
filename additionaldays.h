#ifndef ADDITIONALDAYS_H
#define ADDITIONALDAYS_H

#include <QDialog>

namespace Ui {
class additionalDays;
}

class additionalDays : public QDialog
{
    Q_OBJECT

public:
    explicit additionalDays(QWidget *parent = nullptr);
    ~additionalDays();
    void accept();
signals:
    void setadditionaldays(const QString id, const QString days);
private:
    Ui::additionalDays *ui;
};

#endif // ADDITIONALDAYS_H
