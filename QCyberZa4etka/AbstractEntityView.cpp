#include "AbstractEntityView.hpp"

AbstractEntityPresenation::AbstractEntityPresenation(QWidget *parent) noexcept: QWidget(parent)
{

}

AbstractEntityPresenation::~AbstractEntityPresenation() noexcept
{

}

void AbstractEntityPresenation::setEntity(AbstractEntity *__entity__) noexcept
{
    entity = __entity__;
    updatePresentation();
}
