#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QLabel>
#include "kinds.h"

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

public slots:
private slots:
    void on_action_triggered();

private:
    QLabel *tipLbl;  //"欢迎登录"标签
    Ui::MainWindow *ui;
    kinds *dlgKinds;
    bool connectDatabase();
    void initTableView();
};

#endif // MAINFORM_H
