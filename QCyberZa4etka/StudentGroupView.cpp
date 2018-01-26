#include "StudentGroupView.hpp"

AbstractEntityPresenation *StudentList::getPresentation() const noexcept
{
    assert(presentation != nullptr);

    return presentation;
}

StudentList::StudentList(QWidget *parent) noexcept: QAbstractListModel(parent)
{
    presentation = new StudentPresentation(parent);
}

StudentList::~StudentList() noexcept
{
    for (Student *stud: list)
        delete stud;
}

void StudentList::addStudent(Student *student) noexcept
{
    list.append(student);
}

void StudentList::onSelectedItemsChanged(QItemSelection selected, [[maybe_unused]] QItemSelection deselected)
{
    if (!selected.isEmpty())
    {
        const auto index = selected.indexes().first().row();

        presentation->setEntity(list.at(index));

    }
}

Student* StudentList::getCurrentStudent() noexcept
{
    return list.at(current);
}

int StudentList::rowCount([[maybe_unused]] const QModelIndex &parent) const
{
    return list.size();
}

QVariant StudentList::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    current = (size_t)index.row();

    const int       displayOrEdirRole   = role == Qt::DisplayRole || role == Qt::EditRole;
    const Student   *ret                = list.at(index.row());

    return displayOrEdirRole ? ret->getFullName() : QVariant();
}


//bool StudentList::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    if (index.isValid() && role == Qt::EditRole)
//    {
//        list.replace(index.row(), value.value<Student>());
//        emit dataChanged(index, index);

//        return true;
//    }

//    return false;
//}

QVariant StudentList::headerData([[maybe_unused]] int section, [[maybe_unused]] Qt::Orientation orientation, [[maybe_unused]] int role) const
{
    return "Undefined header";
}

Qt::ItemFlags StudentList::flags([[maybe_unused]] const QModelIndex &index) const
{
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}
