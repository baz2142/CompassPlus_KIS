#ifndef ABSTRACTENITIESVIEW_HPP
#define ABSTRACTENITIESVIEW_HPP

#include <QWidget>
#include <QAbstractItemView>
#include <QAbstractItemModel>
#include <QSplitter>
#include <QVBoxLayout>

#include "AbstractEntityView.hpp"

class AbstractEnitiesView: public QWidget
{
    Q_OBJECT

protected:
    QWidget *groupViewCanvas            = nullptr;
    QWidget *entityViewCanvas           = nullptr;

    QAbstractItemModel  *groupModel     = nullptr;
    QAbstractItemView   *groupView      = nullptr;
    AbstractEntityView  *entityView     = nullptr;

    virtual void setupSignals() noexcept = 0;
    virtual void setupLayout() noexcept;

public:
    explicit AbstractEnitiesView(QAbstractItemModel *__groupModel,
                                 QAbstractItemView *__groupView,
                                 AbstractEntityView *__entityView,
                                 QWidget *parent = nullptr) noexcept;

    //virtual void setModel() noexcept = 0;

    void setGroupModelView(QAbstractItemModel *__groupModel, QAbstractItemView *__groupView) noexcept;
    void setEntityView(AbstractEntityView *value) noexcept;

signals:

public slots:
};

#endif // ABSTRACTENITIESVIEW_HPP
