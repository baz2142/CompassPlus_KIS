#include "StudentView.hpp"

StudentView::StudentView(QWidget *parent) noexcept: AbstractEntityView(parent)
{
    setupLayout();

    createNewButton->setRole(Material::Role::Primary);

    setupTextLine(firstNameEdit, "First name");
    setupTextLine(middleNameEdit, "Middle name");
    setupTextLine(lastNameEdit, "Last name");
    setupTextLine(phoneEdit, "Phone number");
    setupTextLine(passportEdit, "Passsport number");
}


void StudentView::updateEntityView() noexcept
{
    const Student *stud = dynamic_cast<Student*>(entity);

    firstNameEdit->setText(stud->getFirstName());
    middleNameEdit->setText(stud->getMiddleName());
    lastNameEdit->setText(stud->getLastName());
    phoneEdit->setText(stud->getPhoneNumber());
    passportEdit->setText(stud->getPassportNumber());
}

void StudentView::setupLayout() noexcept
{
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(createNewButton);
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(removeButton);

    layout->addLayout(buttonLayout);
    layout->addWidget(firstNameEdit);
    layout->addWidget(middleNameEdit);
    layout->addWidget(lastNameEdit);
    layout->addWidget(phoneEdit);
    layout->addWidget(passportEdit);

    layout->setAlignment(Qt::AlignTop);

    setLayout(layout);
}

void StudentView::setupTextLine(QtMaterialTextField *textLine, const QString &textLabel) noexcept
{
    textLine->setLabelColor(QColor().black());
    textLine->setLabel(textLabel);
    textLine->setUseThemeColors(true);
    textLine->setPlaceholderText("Input an information");
    textLine->setShowInputLine(true);
}


void StudentView::updateEntity() const noexcept
{

}
