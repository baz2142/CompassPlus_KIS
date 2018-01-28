#include "AbstractEntityView.hpp"

AbstractEntityView::AbstractEntityView(QWidget *parent) noexcept: QWidget(parent)
{

}

AbstractEntityView::~AbstractEntityView() noexcept
{

}

void AbstractEntityView::setEntity(AbstractEntity *__entity__) noexcept
{
    entity = __entity__;
    updatePresentation();
}
