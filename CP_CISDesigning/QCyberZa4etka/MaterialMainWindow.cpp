#include "MaterialMainWindow.hpp"


void MaterialMainWindow::setupDrawerWithWidgets(QtMaterialDrawer *drawer, const std::vector<QWidget *> &widgets) noexcept
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setAlignment(Qt::AlignTop);

    for (QWidget *widget: widgets)
        layout->addWidget(widget);

    drawer->setDrawerLayout(layout);

    drawer->setClickOutsideToClose(true);
    drawer->setOverlayMode(true);
    drawer->setContentsMargins(10, 0, 0, 0);
}

void MaterialMainWindow::setupMyProfileDrawer() noexcept
{
    drawers[MY_PROFILE] = new QtMaterialDrawer();

    using ButtonType = QtMaterialFlatButton;

    std::vector<QWidget *> widgets;
    widgets.push_back(new ButtonType("Info"));
    widgets.push_back(new ButtonType("Subjects"));
    widgets.push_back(new ButtonType("Exams"));
    widgets.push_back(new ButtonType("Journal"));
    widgets.push_back(new ButtonType("Events"));
    widgets.push_back(new ButtonType("Marks"));

    for (QWidget *widget: widgets)
    {
        ButtonType *button = static_cast<ButtonType*>(widget);
        button->setRole(Material::Primary);
    }

    setupDrawerWithWidgets(drawers[MY_PROFILE], widgets);
}

void MaterialMainWindow::setupGeneralDrawer() noexcept
{
    drawers[GENERAL] = new QtMaterialDrawer();

    QtMaterialFlatButton *students = new QtMaterialFlatButton("Students", Material::Primary);
    connect(students, &QtMaterialFlatButton::clicked, [=](){setMainWidget(new StudentsView);});

    std::vector<QWidget *> widgets;
    widgets.push_back(new QtMaterialFlatButton("Teachers", Material::Primary));
    widgets.push_back(new QtMaterialFlatButton("Groups", Material::Primary));
    widgets.push_back(students);
    widgets.push_back(new QtMaterialFlatButton("Subjects", Material::Primary));

    setupDrawerWithWidgets(drawers[GENERAL], widgets);
}

void MaterialMainWindow::setupReportsDrawer() noexcept
{
    drawers[REPORTS] = new QtMaterialDrawer();

    std::vector<QWidget *> widgets;
    widgets.push_back(new QtMaterialFlatButton("Academic performance graphic", Material::Primary));
    widgets.push_back(new QtMaterialFlatButton("Students attandance", Material::Primary));
    widgets.push_back(new QtMaterialFlatButton("Group attandance", Material::Primary));
    widgets.push_back(new QtMaterialFlatButton("General attandance", Material::Primary));
    widgets.push_back(new QtMaterialFlatButton("Session report", Material::Primary));

    setupDrawerWithWidgets(drawers[REPORTS], widgets);
}

void MaterialMainWindow::setupSettingsDrawer() noexcept
{
    drawers[SETTINGS] = new QtMaterialDrawer();

    std::vector<QWidget *> widgets;
    widgets.push_back(new QtMaterialFlatButton("Configure avatar", Material::Primary));

    setupDrawerWithWidgets(drawers[SETTINGS], widgets);
}

void MaterialMainWindow::setupDrawers() noexcept
{
    setupMyProfileDrawer();
    setupGeneralDrawer();
    setupReportsDrawer();
    setupSettingsDrawer();
}

void MaterialMainWindow::setupTabBar() noexcept
{
    tabsBar->addTab("My Profile");
    tabsBar->addTab("General");
    tabsBar->addTab("Reports");
    tabsBar->addTab("Settings");

    connect(tabsBar, SIGNAL(currentChanged(int)), this, SLOT(openDrawer(int)));
}

void MaterialMainWindow::setupLayout() noexcept
{
    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMenuBar(tabsBar);
    layout->addWidget(drawers[MY_PROFILE]);
    layout->addWidget(drawers[GENERAL]);
    layout->addWidget(drawers[REPORTS]);
    layout->addWidget(drawers[SETTINGS]);
    layout->addWidget(mainWidget);

    mainWidget->setLayout(new QVBoxLayout);
    setLayout(layout);
}

void MaterialMainWindow::openDrawer(int tabIndex) noexcept
{
    qDebug() << "Open drawer: " << tabIndex;
    drawers[tabIndex]->openDrawer();
}

void MaterialMainWindow::setMainWidget(QWidget *widget) noexcept
{
    assert(mainWidget->layout()->children().count() < 2);

    if (!mainWidget->layout()->isEmpty())
    {
        QWidget *current = mainWidget->layout()->itemAt(0)->widget();

        mainWidget->layout()->removeWidget(current);
        delete current;
    }

    mainWidget->layout()->addWidget(widget);
}

void MaterialMainWindow::addButtonToTab(QAbstractButton *button, MaterialMainWindow::CATEGORY_TAB tab) noexcept
{
    drawers[tab]->layout()->addWidget(button);
}

MaterialMainWindow::MaterialMainWindow(QWidget *parent) noexcept:
    QWidget(parent),
    tabsBar(new QtMaterialTabs),
    mainWidget(new QWidget)
{
    setupTabBar();
    setupDrawers();
    setupLayout();

//    setMainWidget(new StudentsView);
}

MaterialMainWindow::~MaterialMainWindow() noexcept
{

}
