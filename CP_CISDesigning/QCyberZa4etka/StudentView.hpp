#ifndef STUDENTPRESENTATION_HPP
#define STUDENTPRESENTATION_HPP

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>

#include "qtmaterialtextfield.h"

#include "Student.hpp"
#include "AbstractEntityView.hpp"

class StudentView: public AbstractEntityView
{
    Q_OBJECT

    QVBoxLayout *layout             = new QVBoxLayout(this);

//    QLabel      *firstNameLabel     = new QLabel("First name", this);
    QtMaterialTextField   *firstNameEdit      = new QtMaterialTextField(this);
//    QLabel      *middleNameLabel    = new QLabel("Middle name", this);
    QtMaterialTextField   *middleNameEdit     = new QtMaterialTextField(this);
//    QLabel      *lastNameLabel      = new QLabel("Last name", this);
    QtMaterialTextField   *lastNameEdit       = new QtMaterialTextField(this);
//    QLabel      *phoneLabel         = new QLabel("Phone number", this);
    QtMaterialTextField   *phoneEdit          = new QtMaterialTextField(this);
//    QLabel      *passportLabel      = new QLabel("Passport", this);
    QtMaterialTextField   *passportEdit       = new QtMaterialTextField(this);

    virtual void updateEntity() const noexcept override final;
    virtual void updatePresentation() noexcept override final;

    void setupLayout() noexcept;
    void setupTextLine(QtMaterialTextField *textLine, const QString &textLabel) noexcept;

public:
    explicit StudentView(QWidget *parent = nullptr) noexcept;
    virtual ~StudentView() noexcept = default;

signals:

public slots:  

};

#endif // STUDENTPRESENTATION_HPP
