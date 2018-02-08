#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <random>

#include <QString>

#include "Utils.hpp"
#include "AbstractHuman.hpp"
#include "DataBase.hpp"

class Student: public Human
{
protected:
    id_type studentId;

public:
    static Student* getRandom() noexcept;

    Student( id_type id__,
             id_type studentId__            = 0,
             const QString &firstName__     = "Undefined",
             const QString &middleName__    = "Undefined",
             const QString &lastName__      = "Undefined",
             const QString &phoneNumber__   = "Undefined",
             const QString &passportNumber__= "Undefined") noexcept;
    virtual ~Student() noexcept = default;

    id_type getStudentId() const noexcept;
    void    setStudentId(const id_type &value) noexcept;

    // AbstractEntity interface
public:
    virtual void insertEntity() const noexcept(false) override;
    virtual void createTable() const noexcept(false) override;
    virtual void saveEntity() const noexcept(false) override;
    virtual void deleteEntity() const noexcept(false) override;
};

#endif // STUDENT_HPP
