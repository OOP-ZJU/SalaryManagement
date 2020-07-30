#ifndef SEARCHPEOPLE_H
#define SEARCHPEOPLE_H

#include <QDialog>

namespace Ui {
class searchPeople;
}

class searchPeople : public QDialog
{
    Q_OBJECT

public:
    explicit searchPeople(QWidget *parent = nullptr);
    ~searchPeople();

    void accept();
signals:
    void searchpeople(const QString name,const QString id, const QString phonenum, const QString department, const QString job);

private:
    Ui::searchPeople *ui;
};

#endif // SEARCHPEOPLE_H
