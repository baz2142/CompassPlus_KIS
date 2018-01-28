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



//Student::~Student() noexcept
//{

//}
