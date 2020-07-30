#ifndef SALARYOFDEPARTMENT_H
#define SALARYOFDEPARTMENT_H

#include <QDialog>

namespace Ui {
class Salaryofdepartment;
}

class Salaryofdepartment : public QDialog
{
    Q_OBJECT

public:
    explicit Salaryofdepartment(QWidget *parent = nullptr);
    ~Salaryofdepartment();

private:
    Ui::Salaryofdepartment *ui;
};

#endif // SALARYOFDEPARTMENT_H
