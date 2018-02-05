#include "StudentListModel.hpp"

StudentListModel::StudentListModel(QWidget *parent) noexcept:
    AbstractEntityListModel(parent)
{

}

StudentListModel::~StudentListModel() noexcept
{

}

QVariant StudentListModel::data(const QModelIndex &index, int role) const noexcept
{
    if (!index.isValid())
        return QVariant();

    current = (size_t)index.row();

    const int       displayOrEdirRole   = role == Qt::DisplayRole || role == Qt::EditRole;
    const Student   *ret                = (Student*)list.at(index.row());

    return displayOrEdirRole ? ret->getFullName() : QVariant();
}

//bool StudentListModel::setData(const QModelIndex &index, const QVariant &value, int role) noexcept
//{
//    if (index.isValid() && role == Qt::EditRole)
//    {
//        list.replace(index.row(), value.value());
//        emit dataChanged(index, index);

//        return true;
//    }

//    return false;
//}

QVariant StudentListModel::headerData(int section, Qt::Orientation orientation, int role) const noexcept
{
    return "Undefined header";
}

Qt::ItemFlags StudentListModel::flags(const QModelIndex &index) const noexcept
{
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}
