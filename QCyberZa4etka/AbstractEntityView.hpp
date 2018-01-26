#ifndef ABSTRACTENTITYPRESENATION_HPP
#define ABSTRACTENTITYPRESENATION_HPP

#include <QWidget>

#include <AbstractEntity.hpp>

class AbstractEntityPresenation: public QWidget
{
    Q_OBJECT

protected:
    AbstractEntity *entity = nullptr;

    virtual void updateEntity() const noexcept = 0;
    virtual void updatePresentation() noexcept = 0;

public:
    explicit AbstractEntityPresenation(QWidget *parent = nullptr) noexcept;
    virtual ~AbstractEntityPresenation() noexcept;

signals:

public slots:
    void setEntity(AbstractEntity *entity) noexcept;
};

#endif // ABSTRACTENTITYPRESENATION_HPP
