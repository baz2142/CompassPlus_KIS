#include "AbstractEntityView.hpp"

AbstractEntityView::AbstractEntityView(QWidget *parent) noexcept: QWidget(parent)
{
    qDebug() << "AbstractEntityView";
}

AbstractEntityView::~AbstractEntityView() noexcept
{
    // Удалением занимается groupView
}

void AbstractEntityView::setEntity(AbstractEntity *__entity__) noexcept
{
    qDebug() << "setEntity";
    entity = __entity__;
    updateEntityView();
}
