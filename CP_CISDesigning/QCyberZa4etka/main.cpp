#include <QApplication>

#include "MaterialMainWindow.hpp"

int main(int argc, char *argv[])
{
    srandom(time(0));

    QApplication a(argc, argv);
//    MainWindow w;
//    w.resize(800, 600);
//    w.show();

//    Student stud = Student::getRandom();
//    StudentPresentation w;
//    w.setEntity(&stud);

    MaterialMainWindow w;
    w.resize(1280, 720);
    w.show();


    return a.exec();
}
