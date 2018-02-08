#include "AbstractEntityListModel.hpp"

AbstractEntityView* AbstractEntityListModel::getEntityView() const noexcept
{
    return entityView;
}

id_type AbstractEntityListModel::getNextId() const
{
    return list.last()->getId() + 1;
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

void AbstractEntityListModel::onSave()
{
    getCurrentEntity()->saveEntity();
}

void AbstractEntityListModel::onRemove()
{
    AbstractEntity *currEntity = getCurrentEntity();

    list.removeAt(current);
    currEntity->deleteEntity();

    delete currEntity;
}

AbstractEntity* AbstractEntityListModel::getCurrentEntity() noexcept
{
    return list.at(current);
}

int AbstractEntityListModel::rowCount(const QModelIndex &parent) const
{
    return list.size();
}
