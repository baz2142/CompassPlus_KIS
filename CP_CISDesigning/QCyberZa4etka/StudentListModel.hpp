#ifndef STUDENTLISTMODEL_HPP
#define STUDENTLISTMODEL_HPP

#include "AbstractEntityListModel.hpp"
#include "Student.hpp"
#include "StudentView.hpp"

class StudentListModel: public AbstractEntityListModel
{
    Q_OBJECT
public:
    StudentListModel(QWidget *parent = nullptr) noexcept;
    virtual ~StudentListModel() noexcept;

    // QAbstractItemModel interface
public:
    virtual QVariant data(const QModelIndex &index, int role) const noexcept override;
//    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) noexcept override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const noexcept override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const noexcept override;

};

#endif // STUDENTLISTMODEL_HPP
