#include "MainAppWindow.hpp"
#include "ui_MainAppWindow.h"

MainAppWindow::MainAppWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainAppWindow)
{
    ui->setupUi(this);
}

MainAppWindow::~MainAppWindow()
{
    delete ui;
}
