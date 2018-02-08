#include "StudentsView.hpp"

void StudentsView::addStudent(Student *student) noexcept
{
    ((StudentListModel*)groupModel)->addEntity(student);
}

StudentsView::StudentsView(QWidget *parent) noexcept:
    AbstractEnitiesView(new StudentListModel, new QListView, new StudentView, parent)
{
    addStudent(Student::getRandom());
    addStudent(Student::getRandom());
    addStudent(Student::getRandom());

    ((StudentListModel*)groupModel)->setEntityView(entityView);

    setupSignals();
}


void StudentsView::setupSignals() noexcept
{
    const QItemSelectionModel *selectionModel = groupView->selectionModel();

    connect(selectionModel, SIGNAL(selectionChanged(QItemSelection, QItemSelection)),
            groupModel, SLOT(onSelectedItemsChanged(QItemSelection, QItemSelection)));
    connect(entityView, SIGNAL(createPressed()), groupModel, SLOT(onCreateNew()));
}
