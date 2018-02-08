#include "Student.hpp"

Student* Student::getRandom() noexcept
{
    return new Student(rand() % 150,
                   rand() % 150,
                   randomQString(),
                   randomQString(),
                   randomQString(),
                   randomQString(),
                   randomQString());
}

Student::Student(id_type id__,
                 id_type studentId__,
                 const QString &firstName__,
                 const QString &middleName__,
                 const QString &lastName__,
                 const QString &phoneNumber__,
                 const QString &passportNumber__) noexcept:
    Human(id__, firstName__, middleName__, lastName__, phoneNumber__, passportNumber__), studentId(studentId__)
{

}

id_type Student::getStudentId() const noexcept
{
    return studentId;
}

void Student::setStudentId(const id_type &value) noexcept
{
    studentId = value;
}

void Student::insertEntity() const noexcept(false)
{
    QSqlQuery query;

    query.prepare("INSERT INTO Students"
                  "(id, firstName, middleName,"
                  "lastName, phoneNumber, passportNumber"
                  "VALUES (:id, :firstName, :middleName,"
                  ":lastName, :phoneNumber, :passportNumber)");

    query.bindValue(":id",              QString::number(id));
    query.bindValue(":firstName",       firstName);
    query.bindValue(":middleName",      middleName);
    query.bindValue(":lastName",        lastName);
    query.bindValue(":phoneNumber",     phoneNumber);
    query.bindValue(":passportNumber",  passportNumber);

    if (!query.exec())
    {
        qDebug() << "error insert into Students";
        qDebug() << query.lastError().text();

        throw DBException(query.lastError().text());
    }
}

void Student::createTable() const noexcept(false)
{
    QSqlQuery query;

    query.prepare
    (             "CREATE TABLE `Students` ("
                  "`id`               INTEGER NOT NULL,"
                  "`firstName`        TEXT,"
                  "`middleName`       TEXT,"
                  "`lastName`         TEXT,"
                  "`phoneNumber`      TEXT,"
                  "`passportNumber`   TEXT,"
                  "PRIMARY KEY(`id`)"
                  ");"
    );

    if (!query.exec())
    {
        qDebug() << "DataBase: error of create a new Student";
        qDebug() << query.lastError().text();

        throw DBException(query.lastError().text());
    }
}

void Student::saveEntity() const noexcept(false)
{
}

void Student::deleteEntity() const noexcept(false)
{
}
