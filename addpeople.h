#ifndef ADDPEOPLE_H
#define ADDPEOPLE_H

#include <QDialog>

namespace Ui {
class addPeople;
}

class addPeople : public QDialog
{
    Q_OBJECT

public:
    explicit addPeople(QWidget *parent = nullptr);
    ~addPeople();

    void accept();
signals:
    void addpeople(const QString name,const QString id, const QString sex, const QString phonenum, const QString department, const QString job, const QString salary);

private:
    Ui::addPeople *ui;
};

#endif // ADDPEOPLE_H
