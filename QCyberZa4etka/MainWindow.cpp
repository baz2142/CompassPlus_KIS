#include "MainWindow.hpp"

void MainWindow::setupLayout() noexcept
{
    layout = new QSplitter(Qt::Horizontal);
    layout->addWidget(view);
    layout->addWidget(presentation);


    setCentralWidget(layout);
}

MainWindow::MainWindow(QWidget *parent) noexcept: QMainWindow(parent)
{
    StudentList *list = new StudentList(this);

    list->addStudent(Student::getRandom());
    list->addStudent(Student::getRandom());
    list->addStudent(Student::getRandom());

    model = list;

    view = new QListView(this);
    view->setModel(model);
    view->resize(300, 300);

    presentation = list->getPresentation();

    const QItemSelectionModel *selectionModel = view->selectionModel();

    connect(selectionModel, SIGNAL(selectionChanged(QItemSelection, QItemSelection)), list, SLOT(onSelectedItemsChanged(QItemSelection, QItemSelection)));

    //view->setSizePolicy(QSizePolicy::Expanding);

    setupLayout();
}

MainWindow::~MainWindow() noexcept
{

}
