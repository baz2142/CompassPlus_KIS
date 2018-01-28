#include "AbstractEntity.hpp"

AbstractEntity::AbstractEntity(id_type id__) noexcept: id(id__)
{

}

id_type AbstractEntity::getId() const noexcept
{
    return id;
}

void AbstractEntity::setId(const id_type &value) noexcept
{
    id = value;
}
