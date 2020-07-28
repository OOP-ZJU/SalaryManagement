#include "databaseserver.h"

DatabaseServer::DatabaseServer()
{

}

bool DatabaseServer::connectDB()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("SalaryManagement.db");    //如果本目录下没有该文件,则会在本目录下生成,否则连接该文件,/scooters.dat
    if (!database.open())
    {
        QMessageBox::warning(0, QObject::tr("Database Error"),
                             database.lastError().text());
        return false;
    }
    return true;
}

void DatabaseServer::createDB()
{
    QString querystring;
    if(!database.open())    //open the database
    {
        qDebug() << "Database open failed!";
        return;
    }
    //create information table
    querystring = "create table if not exists information"
                   "(id char(10) primary key,"
                    "name varchar(25),"
                    "sex char(1),"
                    "phone_number varchar(11),"
                    "department varchar(40),"
                    "job varchar(25),"
                    "salary decimal(7,2),"
                    "check (sex in ('F','M'))"
                    ")";
    database.exec(querystring);
    if(database.lastError().isValid())
    {
        qDebug() << "table information created failed: " << database.lastError();
        return;
    }
    //create salary table
    querystring = "create table if not exists salary"
                  "(id char(10) primary key,"
                   "name varchar(25),"
                   "salary decimal(7,2),"
                   "allowance decimal(7,2),"
                   "attendance int,"
                   "foreign key (id) references information (id),"
                   "foreign key (name) references information (name)"
                   ")";
    database.exec(querystring);
    if(database.lastError().isValid())
    {
        qDebug() << "table salary created failed: " << database.lastError();
        return;
    }
}

//initialize the database
void DatabaseServer::initDB()
{
    QSqlQuery query(database);
    QString sql[4] = {"insert into information values('0000000001','Ylc','M','1111','Sci','Manager',11.22)",
                      "insert into information values('0000000002','Sxj','M','1111','Atu','Manager',33.22)",
                      "insert into information values('0000000003','Shy','M','1111','Wto','Manager',44.33)",
                      "insert into information values('0000000004','Wyj','M','1111','Cvj','Manager',55.66)"};
    QString judge;  //judge whether the record is in the table
    for(int i = 0; i < 4; ++i)
    {
        judge = QString("select * from information where id = '%1'").arg(i+1,10,10,QLatin1Char('0'));
        if(!query.exec(judge))
        {
            qDebug() << "judge error" <<query.lastError();
            return;
        }
        if(!query.next())   //if not in the table, then insert it
        {
            if(!query.exec(sql[i]))
            {
                qDebug() << "insert failed: " << query.lastError();
            }
        }
        else
        {
            qDebug() << "the record already exists";
        }
    }
}
