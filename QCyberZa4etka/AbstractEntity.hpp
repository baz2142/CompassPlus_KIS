#ifndef ABSTRACTENTITY_HPP
#define ABSTRACTENTITY_HPP

#include "CommonTypes.hpp"

class AbstractEntity
{
protected:
    id_type id = 0ul;

public:
    AbstractEntity(id_type id__ = 0ul) noexcept;
    virtual ~AbstractEntity() noexcept = default;

    void    setId(const id_type &value) noexcept;
    id_type getId() const noexcept;
};

#endif // ABSTRACTENTITY_HPP
