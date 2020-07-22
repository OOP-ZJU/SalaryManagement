#ifndef KINDS_H
#define KINDS_H

#include <QDialog>

namespace Ui {
class kinds;
}

class kinds : public QDialog
{
    Q_OBJECT

public:
    explicit kinds(QWidget *parent = nullptr);
    ~kinds();

private:
    Ui::kinds *ui;
};

#endif // KINDS_H
