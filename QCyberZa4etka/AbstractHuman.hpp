#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <QString>

#include "AbstractEntity.hpp"
#include "CommonTypes.hpp"

class Human: public AbstractEntity
{
protected:
    QString     firstName       = "Undefined";
    QString     middleName      = "Undefined";
    QString     lastName        = "Undefined";
    QString     phoneNumber     = "Undefined";
    QString     passportNumber  = "Undefined";

public:

    Human() noexcept;
    Human(id_type id__,
          const QString &firstName__,
          const QString &middleName__,
          const QString &lastName__,
          const QString &phoneNumber__,
          const QString &passportNumber__) noexcept;
    Human(const Human &human) noexcept = default;
    virtual ~Human() noexcept = default;

    void        setId(const id_type &value) noexcept;
    void        setFirstName(const QString &value) noexcept;
    void        setMiddleName(const QString &value) noexcept;
    void        setLastName(const QString &value) noexcept;
    void        setPhoneNumber(const QString &value) noexcept;
    void        setPassportNumber(const QString &value) noexcept;

    id_type     getId() const noexcept;
    QString     getFullName() const noexcept;
    QString     getFirstName() const noexcept;
    QString     getMiddleName() const noexcept;
    QString     getLastName() const noexcept;
    QString     getPhoneNumber() const noexcept;
    QString     getPassportNumber() const noexcept;
};

#endif // ABSTRACTHUMAN_HPP
