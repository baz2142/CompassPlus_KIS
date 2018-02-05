#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#include <exception>

static class DataBase: public QObject
{
    Q_OBJECT

    QString dbPath;
    QString hostName;

public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();

    void connectToDataBase();

    QString getDbPath() const;
    void setDbPath(const QString &value);

    QString getHostName() const;
    void setHostName(const QString &value);

private:
    QSqlDatabase db;

private:

    bool openDataBase();
    void closeDataBase();
} dataBase;

class DBException: std::exception
{
protected:
    QString msg;

public:
    DBException(const QString &text) noexcept: msg(text) {}
    virtual const char* what() const noexcept override {return msg.toStdString().c_str();}
};

#endif // DATABASE_H
