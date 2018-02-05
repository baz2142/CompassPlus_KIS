#include <random>
#include <QApplication>

//#include "StudentsView.hpp"
#include "MaterialMainWindow.hpp"


int main(int argc, char *argv[])
{
    srand(time(0));

#ifdef WIN32
    QCoreApplication::addLibraryPath("C:/Users/nbazulin/5.10.0/mingw53_32/plugins");
#endif
    QApplication a(argc, argv);


//    MainWindow w;
//    w.resize(800, 600);
//    w.show();

//    Student stud = Student::getRandom();
//    StudentPresentation w;
//    w.setEntity(&stud);

//    QWidget w;

//    StudentView         *entityView = new StudentView;
//    QListView           *groupView  = new QListView;
//    StudentListModel    *model      = new StudentListModel;

//    QVBoxLayout *lay = new QVBoxLayout;
//    lay->addWidget(groupView);
//    lay->addWidget(entityView);
//    w.setLayout(lay);

//    groupView->setModel(model);
//    model->addEntity(Student::getRandom());
//    model->addEntity(Student::getRandom());
//    model->addEntity(Student::getRandom());


    MaterialMainWindow w;
    w.resize(1280, 720);
    w.show();


    return a.exec();
}
