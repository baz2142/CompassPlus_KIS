#ifndef ABSTRACTENTITY_HPP
#define ABSTRACTENTITY_HPP

#include <QString>

#include "CommonTypes.hpp"
#include "DataBase.hpp"

class AbstractEntity
{
protected:
    id_type id = 0ul;

public:
    virtual void createTable() const noexcept(false) = 0;
    virtual void insertEntity() const noexcept(false) = 0;
    virtual void saveEntity() const noexcept(false) = 0;
    virtual void deleteEntity() const noexcept(false) = 0;

    AbstractEntity(id_type id__ = 0ul) noexcept;
    virtual ~AbstractEntity() noexcept = default;

    void    setId(const id_type &value) noexcept;
    id_type getId() const noexcept;
};

#endif // ABSTRACTENTITY_HPP
