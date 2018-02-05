//#include "MainWindow.hpp"

//void MainWindow::setupLayout() noexcept
//{
//    layout = new QSplitter(Qt::Horizontal);
//    layout->addWidget(groupView);
//    layout->addWidget(entityView);

//    setCentralWidget(layout);
//    setStyleSheet("background-color:white;");
//}

//MainWindow::MainWindow(QWidget *parent) noexcept: QMainWindow(parent)
//{
//    AbstractEntityListModel *list = new AbstractEntityListModel(this);

//    list->addEntity(Student::getRandom());
//    list->addEntity(Student::getRandom());
//    list->addEntity(Student::getRandom());

//    groupModel = list;

//    groupView = new QListView(this);
//    groupView->setModel(groupModel);
//    groupView->resize(300, 300);

//    entityView = list->getEntityView();

//    const QItemSelectionModel *selectionModel = groupView->selectionModel();

//    connect(selectionModel, SIGNAL(selectionChanged(QItemSelection, QItemSelection)), list, SLOT(onSelectedItemsChanged(QItemSelection, QItemSelection)));

//    //view->setSizePolicy(QSizePolicy::Expanding);

//    setupLayout();
//}

//MainWindow::~MainWindow() noexcept
//{

//}
