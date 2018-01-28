#ifndef MATERIALMAINWINDOW_HPP
#define MATERIALMAINWINDOW_HPP

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

#include "qtmaterialtabs.h"
#include <qtmaterialiconbutton.h>
#include <qtmaterialdrawer.h>

#include <lib/qtmaterialtheme.h>

class MaterialMainWindow: public QWidget
{
    Q_OBJECT

    QtMaterialTabs      *tabs       = nullptr;
    QtMaterialDrawer    *sidePanel  = nullptr;

    void setupSidePanel() noexcept;
    void setupTabBar() noexcept;
    void setupLayout() noexcept;

public:
    explicit MaterialMainWindow(QWidget *parent = 0) noexcept;
    ~MaterialMainWindow() noexcept;
};

#endif // MATERIALMAINWINDOW_HPP
