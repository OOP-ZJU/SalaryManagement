#ifndef MODIFYPEOPLE_H
#define MODIFYPEOPLE_H

#include <QDialog>

namespace Ui {
class modifyPeople;
}

class modifyPeople : public QDialog
{
    Q_OBJECT

public:
    explicit modifyPeople(QWidget *parent = nullptr);
    ~modifyPeople();

    void accept();
signals:
    void modifypeople(const QString name,const QString id, const QString sex, const QString phonenum, const QString department, const QString job);

private:
    Ui::modifyPeople *ui;
};

#endif // MODIFYPEOPLE_H
