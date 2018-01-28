#ifndef STUDENTLIST_HPP
#define STUDENTLIST_HPP

#include <QWidget>
#include <QAbstractListModel>
#include <QItemSelection>

#include "StudentView.hpp"
#include "Student.hpp"

class StudentList: public QAbstractListModel
{
    Q_OBJECT

    mutable size_t              current         = 0;
    QList<Student*>             list;
    AbstractEntityView   *presentation   = nullptr;

public:

    explicit StudentList(QWidget *parent = nullptr) noexcept;
    virtual ~StudentList() noexcept;

    void addStudent(Student *student) noexcept;

signals:

public slots:
    void onSelectedItemsChanged(QItemSelection selected, QItemSelection deselected);

    Student* getCurrentStudent() noexcept;

    // QAbstractItemModel interface
public:
    virtual int         rowCount(const QModelIndex &parent) const override;
    virtual QVariant    data(const QModelIndex &index, int role) const override;

    AbstractEntityView* getPresentation() const noexcept;


//    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual QVariant        headerData(int section, Qt::Orientation orientation, int role) const override;
    virtual Qt::ItemFlags   flags(const QModelIndex &index) const override;

};

#endif // STUDENT_HPP
