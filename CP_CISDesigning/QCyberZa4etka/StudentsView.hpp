#ifndef STUDENTSVIEW_HPP
#define STUDENTSVIEW_HPP

#include <QWidget>
#include <AbstractEnitiesView.hpp>
#include <QListView>

#include "StudentListModel.hpp"
#include "StudentView.hpp"

class StudentsView: public AbstractEnitiesView
{
    Q_OBJECT

public:
    explicit StudentsView(QWidget *parent = nullptr) noexcept;

    void addStudent(Student *student) noexcept;

signals:

public slots:

    // AbstractEnitiesView interface
protected:
    virtual void setupSignals() noexcept override;
};

#endif // STUDENTSVIEW_HPP
