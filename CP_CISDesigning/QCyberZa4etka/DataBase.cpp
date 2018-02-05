#include "DataBase.hpp"

QString DataBase::getDbPath() const
{
    return dbPath;
}

void DataBase::setDbPath(const QString &value)
{
    dbPath = value;
}

QString DataBase::getHostName() const
{
    return hostName;
}

void DataBase::setHostName(const QString &value)
{
    hostName = value;
}

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}


void DataBase::connectToDataBase()
{
    if (QFile(dbPath).exists())
        this->openDataBase();
    else
        throw DBException("Couldn't connect to DB");
}

bool DataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(hostName);
    db.setDatabaseName(dbPath);

    return db.open();
}

void DataBase::closeDataBase()
{
    db.close();
}


