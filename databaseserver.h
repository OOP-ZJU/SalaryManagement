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
private:
    QSqlDatabase database;
};

#endif // DATABASESERVER_H
