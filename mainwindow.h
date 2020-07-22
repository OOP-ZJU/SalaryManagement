#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QLabel>

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
private:
    QLabel *tipLbl;  //"欢迎登录"标签
    Ui::MainWindow *ui;

    bool connectDatabase();
    void initTableView();
};

#endif // MAINFORM_H
