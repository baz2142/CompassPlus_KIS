#ifndef ABSTRACTENTITYPRESENATION_HPP
#define ABSTRACTENTITYPRESENATION_HPP

#include <cassert>

#include <QWidget>
#include <QDebug>

#include "AbstractEntity.hpp"


class AbstractEntityView: public QWidget
{
    Q_OBJECT

protected:
    AbstractEntity *entity = nullptr;

    virtual void updateEntity() const noexcept = 0;
    virtual void updateEntityView() noexcept = 0;

public:
    explicit AbstractEntityView(QWidget *parent = nullptr) noexcept;
    virtual ~AbstractEntityView() noexcept;

signals:

public slots:
    void setEntity(AbstractEntity *entity) noexcept;
};

#endif // ABSTRACTENTITYPRESENATION_HPP
