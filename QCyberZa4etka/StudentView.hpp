#ifndef STUDENTPRESENTATION_HPP
#define STUDENTPRESENTATION_HPP

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>

#include "Student.hpp"
#include "AbstractEntityView.hpp"

class StudentPresentation: public AbstractEntityPresenation
{
    Q_OBJECT

    QGridLayout *layout             = new QGridLayout(this);

    QLabel      *firstNameLabel     = new QLabel("First name", this);
    QLineEdit   *firstNameEdit      = new QLineEdit(this);
    QLabel      *middleNameLabel    = new QLabel("Middle name", this);
    QLineEdit   *middleNameEdit     = new QLineEdit(this);
    QLabel      *lastNameLabel      = new QLabel("Last name", this);
    QLineEdit   *lastNameEdit       = new QLineEdit(this);
    QLabel      *phoneLabel         = new QLabel("Phone number", this);
    QLineEdit   *phoneEdit          = new QLineEdit(this);
    QLabel      *passportLabel      = new QLabel("Passport", this);
    QLineEdit   *passportEdit       = new QLineEdit(this);

    virtual void updateEntity() const noexcept override final;
    virtual void updatePresentation() noexcept override final;

    void setupLayout() noexcept;

public:
    explicit StudentPresentation(QWidget *parent = nullptr) noexcept;
    virtual ~StudentPresentation() noexcept = default;

signals:

public slots:  

};

#endif // STUDENTPRESENTATION_HPP
