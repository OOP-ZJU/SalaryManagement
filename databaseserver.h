#ifndef DATABASESERVER_H
#define DATABASESERVER_H
#include "QtSql"
#include "QMessageBox"
#include "QApplication"

class DatabaseServer
{
public:
    DatabaseServer();
    bool connectDB();
    void initDB();
    void createDB();
    static int getExtraWork(const QString id);
    static int getAttendance(const QString id);
    static void setSalaryTaxed(const QString id, const QString salaryTaxed);
private:
    QSqlDatabase database;
};

#endif // DATABASESERVER_H
