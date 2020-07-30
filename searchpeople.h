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

private:
    Ui::searchPeople *ui;
};

#endif // SEARCHPEOPLE_H
