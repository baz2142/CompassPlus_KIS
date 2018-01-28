#include "MarksView.hpp"
#include "ui_MarksView.h"

MarksView::MarksView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarksView)
{
    ui->setupUi(this);
}

MarksView::~MarksView()
{
    delete ui;
}
