#include "AbstractEnitiesView.hpp"

AbstractEnitiesView::AbstractEnitiesView(QAbstractItemModel *__groupModel,
                                         QAbstractItemView *__groupView,
                                         AbstractEntityView *__entityView,
                                         QWidget *parent) noexcept:
    QWidget(parent),
    groupViewCanvas(new QWidget),
    entityViewCanvas(new QWidget)
{
    setupLayout();

    setGroupModelView(__groupModel, __groupView);
    setEntityView(__entityView);
}

void AbstractEnitiesView::setGroupModelView(QAbstractItemModel *__groupModel, QAbstractItemView *__groupView) noexcept
{
    groupView = __groupView;
    groupModel = __groupModel;

    groupView->setModel(groupModel);
    groupViewCanvas->layout()->addWidget(groupView);
}

void AbstractEnitiesView::setEntityView(AbstractEntityView *value) noexcept
{
    entityView = value;
    entityViewCanvas->layout()->addWidget(entityView);
}

void AbstractEnitiesView::setupLayout() noexcept
{
    QSplitter *splitter = new QSplitter(Qt::Horizontal);

    groupViewCanvas->setLayout(new QVBoxLayout);
    entityViewCanvas->setLayout(new QVBoxLayout);

    splitter->addWidget(groupViewCanvas);
    splitter->addWidget(entityViewCanvas);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(splitter);

    setLayout(layout);
    setStyleSheet("background-color:white;");
}

//MainWindow::MainWindow(QWidget *parent) noexcept: QMainWindow(parent)
//{
//    StudentGroupView *list = new StudentGroupView(this);

//    list->addStudent(Student::getRandom());
//    list->addStudent(Student::getRandom());
//    list->addStudent(Student::getRandom());

//    model = list;

//    entityView = new QListView(this);
//    entityView->setModel(model);
//    entityView->resize(300, 300);

//    groupView = list->getEntityView();

//    const QItemSelectionModel *selectionModel = entityView->selectionModel();

//    connect(selectionModel, SIGNAL(selectionChanged(QItemSelection, QItemSelection)), list, SLOT(onSelectedItemsChanged(QItemSelection, QItemSelection)));

//    //view->setSizePolicy(QSizePolicy::Expanding);

//    setupLayout();
//}
