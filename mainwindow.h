#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QLabel>
#include "kinds.h"
#include "databaseserver.h"
#include "addpeople.h"
#include "modifypeople.h"
#include "workdays.h"
#include "additionaldays.h"


namespace Ui
{
    class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool setWorkDays(const QString id,const QString days);
    bool changePeople(const QString name,const QString id, const QString sex, const QString phonenum, const QString department, const QString job);
    bool insertPeople(const QString name,const QString id, const QString sex, const QString phonenum, const QString department, const QString job, const QString salary);
    bool deletePeople(const QString id);
    bool setAdditionalDays(const QString id,const QString days);

signals:

public slots:
private slots:
    void on_action_triggered();

    void on_action_7_triggered();

    void on_action_8_triggered();

    void on_action_9_triggered();

    void on_action_10_triggered();

    void on_action_12_triggered();

    void on_action_6_triggered();

private:
    QLabel *tipLbl;  //"欢迎登录"标签
    Ui::MainWindow *ui;
    kinds *dlgKinds;
    DatabaseServer DBS;
    addPeople *dlgAddPeople;
    modifyPeople *dlgModifyPeople;
    workDays *dlgWorkDays;
    additionalDays *dlgAdditionalDays;
    QSqlTableModel *model;
    bool connectDatabase();
    void initTableView();
};

#endif // MAINFORM_H
