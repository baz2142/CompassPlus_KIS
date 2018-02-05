#include "MenuItem.hpp"

MenuItem::MenuItem(QWidget *parent): QWidget(parent), picture(new QtMaterialAvatar), background(new QtMaterialFlatButton)
{
    setupLayout();
    background->setRole(Material::Primary);
}

void MenuItem::setupLayout() noexcept
{
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(picture);

    setLayout(layout);
}
