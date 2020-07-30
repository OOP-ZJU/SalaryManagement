#ifndef SALARYOFCOMPANY_H
#define SALARYOFCOMPANY_H

#include <QDialog>

namespace Ui {
class Salaryofcompany;
}

class Salaryofcompany : public QDialog
{
    Q_OBJECT

public:
    explicit Salaryofcompany(QWidget *parent = nullptr);
    ~Salaryofcompany();

private:
    Ui::Salaryofcompany *ui;
};

#endif // SALARYOFCOMPANY_H
