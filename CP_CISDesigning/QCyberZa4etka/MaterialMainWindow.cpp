#include "MaterialMainWindow.hpp"


void MaterialMainWindow::setupSidePanel() noexcept
{
    //sidePanel->setParent(canvas);
    sidePanel->setClickOutsideToClose(true);
    sidePanel->setOverlayMode(true);

    QVBoxLayout *drawerLayout = new QVBoxLayout;
    sidePanel->setDrawerLayout(drawerLayout);

    QVector<QString> labels = {"Student Diary", "Exams", "Session", "Calendar"};

    QVector<QString>::iterator it;
    for (it = labels.begin(); it != labels.end(); ++it) {
        QLabel *label = new QLabel(*it);
        label->setMinimumHeight(30);
        label->setFont(QFont("Roboto", 10, QFont::Medium));
        drawerLayout->addWidget(label);
    }

    drawerLayout->addStretch(3);
    sidePanel->setContentsMargins(10, 0, 0, 0);
    sidePanel->openDrawer();

    //drawerLayout->addWidget(new QPushButton("abc"));
}

void MaterialMainWindow::setupTabBar() noexcept
{
    tabs->addTab("My profile");
    tabs->addTab("General");
    tabs->addTab("Reports");
    tabs->addTab("Settings");
}

void MaterialMainWindow::setupLayout() noexcept
{
    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMenuBar(tabs);
    layout->addWidget(sidePanel);
    //layout->addWidget(tabs);

    setLayout(layout);
}

MaterialMainWindow::MaterialMainWindow(QWidget *parent) noexcept:
    QWidget(parent),
    tabs(new QtMaterialTabs),
    sidePanel(new QtMaterialDrawer)
{
    setupTabBar();
    setupSidePanel();
    setupLayout();
    //setupAppBar();
}

MaterialMainWindow::~MaterialMainWindow() noexcept
{

}
