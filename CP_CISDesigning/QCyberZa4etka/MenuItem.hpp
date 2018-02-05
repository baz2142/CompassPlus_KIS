#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include <QWidget>
#include <QVBoxLayout>

#include <qtmaterialavatar.h>
#include <qtmaterialflatbutton.h>

class MenuItem : public QWidget
{
    Q_OBJECT
public:
    explicit MenuItem(QWidget *parent = nullptr);

    QtMaterialAvatar        *picture;
    QtMaterialFlatButton    *background;

    void setupLayout() noexcept;

signals:

public slots:
};

#endif // MENUITEM_HPP
