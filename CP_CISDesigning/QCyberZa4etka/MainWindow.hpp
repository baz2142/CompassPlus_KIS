#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QAbstractItemView>
#include <QAbstractItemModel>
#include <QSplitter>

#include <QListView>
#include <QStringListModel>

#include "AbstractEntityView.hpp"
#include "StudentGroupView.hpp"
#include "StudentView.hpp"

class MainWindow: public QMainWindow
{
    Q_OBJECT

    QSplitter                   *layout         = nullptr;
    QAbstractItemModel          *model          = nullptr;

    QAbstractItemView           *view           = nullptr;
    AbstractEntityView   *presentation          = nullptr;

    void setupLayout() noexcept;

public:
    MainWindow(QWidget *parent = 0) noexcept;
    ~MainWindow() noexcept;
};

#endif // MAINWINDOW_HPP
