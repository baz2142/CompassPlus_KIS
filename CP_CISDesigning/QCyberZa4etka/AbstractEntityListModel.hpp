#ifndef ABSTRACTENTITYLISTMODEL_HPP
#define ABSTRACTENTITYLISTMODEL_HPP

#include <cassert>

#include <QWidget>
#include <QAbstractListModel>
#include <QItemSelection>

#include "AbstractEntityView.hpp"
#include "AbstractEntity.hpp"

class AbstractEntityListModel: public QAbstractListModel
{
    Q_OBJECT

protected:
    mutable size_t              current     = 0;
    QList<AbstractEntity*>      list;
    AbstractEntityView          *entityView = nullptr;

    id_type getNextId() const;

public:

    explicit AbstractEntityListModel(QWidget *parent = nullptr) noexcept;
    virtual ~AbstractEntityListModel() noexcept;

    virtual void addEntity(AbstractEntity *entity) noexcept;
    virtual void setEntityView(AbstractEntityView *__entityView) noexcept;
    virtual AbstractEntity* getCurrentEntity() noexcept;

signals:
    void setEntityToView(AbstractEntity*);

public slots:
    virtual void onSelectedItemsChanged(QItemSelection selected, QItemSelection deselected);
    virtual void onCreateNew() = 0;
    virtual void onSave();
    virtual void onRemove();

    // QAbstractItemModel interface
public:
    virtual int         rowCount(const QModelIndex &parent) const override;
//    virtual QVariant    data(const QModelIndex &index, int role) const override;

    virtual AbstractEntityView* getEntityView() const noexcept;

//    virtual bool            setData(const QModelIndex &index, const QVariant &value, int role) = 0;
    virtual QVariant        headerData(int section, Qt::Orientation orientation, int role) const = 0;
    virtual Qt::ItemFlags   flags(const QModelIndex &index) const = 0;

};

#endif // ABSTRACTENTITYLISTMODEL_HPP
