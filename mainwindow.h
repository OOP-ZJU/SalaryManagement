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
#include "additionaldays_show.h"
#include "salaryofdepartment.h"
#include "salaryofcompany.h"
#include "workdays_show.h"
#include "searchpeople.h"


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
    bool search(const QString name,const QString id, const QString phonenum, const QString department, const QString job);
signals:

public slots:
private slots:
    void on_action_triggered();

    void on_action_5_triggered();

    void on_action_7_triggered();

    void on_action_8_triggered();

    void on_action_9_triggered();

    void on_action_10_triggered();

    void on_action_12_triggered();

    void on_action_6_triggered();

    void on_action_3_triggered();

    void on_action_2_triggered();

    void on_action_4_triggered();

private:
    QSqlTableModel *model;
    Ui::MainWindow *ui;
    QLabel *tipLbl;  //"欢迎登录"标签
    kinds *dlgKinds;
    DatabaseServer DBS; // 数据库服务助手，用于操作数据库
    addPeople *dlgAddPeople;
    modifyPeople *dlgModifyPeople;
    workDays *dlgWorkDays;
    workdays_show *dlgworkdays_show;
    additionalDays *dlgAdditionalDays;
    Additionaldays_show *dlgAdditionaldays_show;
    Salaryofdepartment *dlgSalaryofdepartment;
    Salaryofcompany *dlgSlaryofcompany;
    searchPeople *dlgSearchPeople;
    friend class salarydetail;
    void initTableView(); // 把数据库的表格显示在TableView中
    void on_table_clicked(const QModelIndex &index);

};

#endif // MAINFORM_H
