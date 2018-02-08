#ifndef STUDENTPRESENTATION_HPP
#define STUDENTPRESENTATION_HPP

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>

#include "qtmaterialtextfield.h"
#include <qtmaterialraisedbutton.h>

#include "Student.hpp"
#include "AbstractEntityView.hpp"

class StudentView: public AbstractEntityView
{
    Q_OBJECT

    QVBoxLayout *layout = new QVBoxLayout(this);

    QtMaterialRaisedButton *createNewButton     = new QtMaterialRaisedButton("Create new");
    QtMaterialFlatButton   *saveButton          = new QtMaterialFlatButton("Save");
    QtMaterialRaisedButton *removeButton        = new QtMaterialRaisedButton("Remove");

    QtMaterialTextField   *firstNameEdit      = new QtMaterialTextField(this);
    QtMaterialTextField   *middleNameEdit     = new QtMaterialTextField(this);
    QtMaterialTextField   *lastNameEdit       = new QtMaterialTextField(this);
    QtMaterialTextField   *phoneEdit          = new QtMaterialTextField(this);
    QtMaterialTextField   *passportEdit       = new QtMaterialTextField(this);

    virtual void updateEntity() const noexcept override final;
    virtual void updateEntityView() noexcept override final;

    void setupLayout() noexcept;
    void setupTextLine(QtMaterialTextField *textLine, const QString &textLabel) noexcept;

public:
    explicit StudentView(QWidget *parent = nullptr) noexcept;
    virtual ~StudentView() noexcept = default;

signals:

public slots:  

};

#endif // STUDENTPRESENTATION_HPP
