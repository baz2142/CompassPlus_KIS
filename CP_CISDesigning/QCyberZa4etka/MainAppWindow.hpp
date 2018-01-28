#ifndef MAINAPPWINDOW_HPP
#define MAINAPPWINDOW_HPP

#include <QWidget>

namespace Ui {
class MainAppWindow;
}

class MainAppWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainAppWindow(QWidget *parent = 0);
    ~MainAppWindow();

private:
    Ui::MainAppWindow *ui;
};

#endif // MAINAPPWINDOW_HPP
