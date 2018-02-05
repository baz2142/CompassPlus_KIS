#ifndef MATERIALMAINWINDOW_HPP
#define MATERIALMAINWINDOW_HPP

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QTabWidget>
#include <QDebug>

#include <iostream>
#include <array>

#include <qtmaterialraisedbutton.h>
#include <qtmaterialtabs.h>
#include <qtmaterialiconbutton.h>
#include <qtmaterialdrawer.h>
#include <qtmaterialflatbutton.h>
#include <lib/qtmaterialtheme.h>

#include "StudentsView.hpp"
#include "DataBase.hpp"


class MaterialMainWindow: public QWidget
{
    Q_OBJECT

public:
    enum CATEGORY_TAB {MY_PROFILE, GENERAL, REPORTS, SETTINGS};

private:
    static constexpr size_t numOfTabs = 4;

    QtMaterialTabs                              *tabsBar;
    std::array<QtMaterialDrawer*, numOfTabs>    drawers;
    QWidget                                     *mainWidget;

    void setupDrawerWithWidgets(QtMaterialDrawer *drawer, const std::vector<QWidget*> &widgets) noexcept;
    void setupMyProfileDrawer() noexcept;
    void setupGeneralDrawer() noexcept;
    void setupReportsDrawer() noexcept;
    void setupSettingsDrawer() noexcept;

    void setupDrawers() noexcept;
    void setupTabBar() noexcept;
    void setupLayout() noexcept;

public slots:
    void openDrawer(int tabIndex) noexcept;
    void setMainWidget(QWidget *widget) noexcept;

public:
    void addButtonToTab(QAbstractButton *button, CATEGORY_TAB tab) noexcept;

    explicit MaterialMainWindow(QWidget *parent = 0) noexcept;
    ~MaterialMainWindow() noexcept;
};

#endif // MATERIALMAINWINDOW_HPP
