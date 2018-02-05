#include "AbstractEntityListModel.hpp"

AbstractEntityView* AbstractEntityListModel::getEntityView() const noexcept
{
    return entityView;
}

AbstractEntityListModel::AbstractEntityListModel(QWidget *parent) noexcept:
    QAbstractListModel(parent)
{

}

AbstractEntityListModel::~AbstractEntityListModel() noexcept
{
    for (AbstractEntity *entity: list)
        delete entity;
}

void AbstractEntityListModel::addEntity(AbstractEntity *entity) noexcept
{
    list.append(entity);
}

void AbstractEntityListModel::setEntityView(AbstractEntityView *__entityView) noexcept
{
    entityView = __entityView;
}

void AbstractEntityListModel::onSelectedItemsChanged(QItemSelection selected, QItemSelection deselected)
{
    if (!selected.isEmpty())
    {
        current = selected.indexes().first().row();
        entityView->setEntity(getCurrentEntity());

        //emit setEntityToView(getCurrentEntity());
    }
}

AbstractEntity* AbstractEntityListModel::getCurrentEntity() noexcept
{
    return list.at(current);
}

int AbstractEntityListModel::rowCount(const QModelIndex &parent) const
{
    return list.size();
}
