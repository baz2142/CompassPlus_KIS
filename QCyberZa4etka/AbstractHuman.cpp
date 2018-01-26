#include "AbstractHuman.hpp"

Human::Human() noexcept
{

}

Human::Human(id_type id__,
             const QString &firstName__,
             const QString &middleName__,
             const QString &lastName__,
             const QString &phoneNumber__,
             const QString &passportNumber__) noexcept:
    AbstractEntity(id__),
    firstName(firstName__),
    middleName(middleName__),
    lastName(lastName__),
    phoneNumber(phoneNumber__),
    passportNumber(passportNumber__)
{

}

id_type Human::getId() const noexcept
{
    return id;
}

void Human::setId(const id_type &value) noexcept
{
    id = value;
}

QString Human::getFullName() const noexcept
{
    return lastName + " " + firstName + " " + middleName;
}


QString Human::getFirstName() const noexcept
{
    return firstName;
}

void Human::setFirstName(const QString &value) noexcept
{
    firstName = value;
}

QString Human::getMiddleName() const noexcept
{
    return middleName;
}

void Human::setMiddleName(const QString &value) noexcept
{
    middleName = value;
}

QString Human::getLastName() const noexcept
{
    return lastName;
}

void Human::setLastName(const QString &value) noexcept
{
    lastName = value;
}

QString Human::getPhoneNumber() const noexcept
{
    return phoneNumber;
}

void Human::setPhoneNumber(const QString &value) noexcept
{
    phoneNumber = value;
}

QString Human::getPassportNumber() const noexcept
{
    return passportNumber;
}

void Human::setPassportNumber(const QString &value) noexcept
{
    passportNumber = value;
}
