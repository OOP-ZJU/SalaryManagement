#ifndef DATABASESERVER_H
#define DATABASESERVER_H
#include "QtSql"
#include "QMessageBox"
#include "QApplication"

class DatabaseServer
{
public:
    DatabaseServer();
    bool connectDB();   // 连接数据库
    void createDB();    // 新建数据库
    void initDB();      // 初始化数据库

    static int getExtraWork(const QString id);
    static int getAttendance(const QString id);
    static void setSalaryTaxed(const QString id, const QString salaryTaxed);
private:
    QSqlDatabase database;
};

#endif // DATABASESERVER_H
