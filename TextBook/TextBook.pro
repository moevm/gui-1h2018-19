#-------------------------------------------------
#
# Project created by QtCreator 2018-03-10T14:12:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextBook
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    Model/slide.cpp \
    Model/contentitem.cpp \
    Model/contentpart.cpp \
    Model/contentmodel.cpp \
    Model/lecture.cpp \
    Import/xmlimporter.cpp \
    Model/quiz.cpp \
    Model/question.cpp \
    Model/course.cpp \
    optionsdialog.cpp \
    navigatorwidget.cpp

HEADERS  += mainwindow.h \
    Model/slide.h \
    Model/contentitem.h \
    Model/contentpart.h \
    Model/contentmodel.h \
    Model/lecture.h \
    Import/xmlimporter.h \
    Model/quiz.h \
    Model/question.h \
    Model/course.h \
    optionsdialog.h \
    navigatorwidget.h

FORMS    += mainwindow.ui \
    optionsdialog.ui

RESOURCES += \
    resources.qrc
