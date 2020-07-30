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
    static QString getExtraWork(const QString id);
    static QString getAttendance(const QString id);
    static void setExtraWork(const QString id, const QString days);
    static void setAttendance(const QString id, const QString days);
private:
    QSqlDatabase database;
};

#endif // DATABASESERVER_H
