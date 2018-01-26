#include "StudentView.hpp"

StudentPresentation::StudentPresentation(QWidget *parent) noexcept: AbstractEntityPresenation(parent)
{
    setupLayout();
}


void StudentPresentation::updatePresentation() noexcept
{
    const Student *stud = dynamic_cast<Student*>(entity);

    firstNameEdit->setText(stud->getFirstName());
    middleNameEdit->setText(stud->getMiddleName());
    lastNameEdit->setText(stud->getLastName());
    phoneEdit->setText(stud->getPhoneNumber());
    passportEdit->setText(stud->getPassportNumber());
}

void StudentPresentation::setupLayout() noexcept
{
    layout->addWidget(firstNameLabel, 0, 0, Qt::AlignRight);
    layout->addWidget(firstNameEdit, 0, 1);

    layout->addWidget(middleNameLabel, 1, 0, Qt::AlignRight);
    layout->addWidget(middleNameEdit, 1, 1);

    layout->addWidget(lastNameLabel, 2, 0, Qt::AlignRight);
    layout->addWidget(lastNameEdit, 2, 1);

    layout->addWidget(phoneLabel, 3, 0, Qt::AlignRight);
    layout->addWidget(phoneEdit, 3, 1);

    layout->addWidget(passportLabel, 4, 0, Qt::AlignRight);
    layout->addWidget(passportEdit, 4, 1);

    layout->setAlignment(Qt::AlignTop);

    setLayout(layout);
}


void StudentPresentation::updateEntity() const noexcept
{

}
