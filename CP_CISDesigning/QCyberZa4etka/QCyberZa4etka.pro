#-------------------------------------------------
#
# Project created by QtCreator 2017-12-03T13:10:22
#
#-------------------------------------------------

QT       += core gui widgets sql
CONFIG   += c++14

TARGET = QCyberZa4etka
TEMPLATE = app

#LIBS += $$top_builddir/components/libcomponents.a
#INCLUDEPATH +=  $$top_srcdir/components/
#PRE_TARGETDEPS += $$top_builddir/components/$(OBJECTS_DIR)/libcomponents.a

SOURCES += \
        main.cpp \
    Student.cpp \
    AbstractHuman.cpp \
    AbstractEntity.cpp \
    Utils.cpp \
    StudentView.cpp \
    AbstractEntityView.cpp \
    Marks.cpp \
    MarksView.cpp \
    MaterialMainWindow.cpp \
    MyProfileView.cpp \
    StudentsView.cpp \
    AbstractEnitiesView.cpp \
    AbstractEntityListModel.cpp \
    StudentListModel.cpp \
    DataBase.cpp


HEADERS += \
    Student.hpp \
    CommonTypes.hpp \
    AbstractHuman.hpp \
    AbstractEntity.hpp \
    Utils.hpp \
    StudentView.hpp \
    AbstractEntityView.hpp \
    Marks.hpp \
    MarksView.hpp \
    MaterialMainWindow.hpp \
    MyProfileView.hpp \
    StudentsView.hpp \
    AbstractEnitiesView.hpp \
    AbstractEntityListModel.hpp \
    StudentListModel.hpp \
    DataBase.hpp


FORMS += \
    Form.ui \
    MarksView.ui \
    GroupView.ui \
    Journal.ui \
    LoginDialog.ui \
    ProfileInfo.ui \
    Subject.ui \
    ExamsForm.ui \
    EventsForm.ui \
    TeachersForm.ui \
    AcadenicPerformanceGraphicForm.ui \
    AttandanceGeneralForm.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../components/release/ -lcomponents
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../components/debug/ -lcomponents
else:unix: LIBS += -L$$OUT_PWD/../components/ -lcomponents

INCLUDEPATH += $$PWD/../components
DEPENDPATH += $$PWD/../components

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../components/release/libcomponents.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../components/debug/libcomponents.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../components/release/components.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../components/debug/components.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../components/libcomponents.a
