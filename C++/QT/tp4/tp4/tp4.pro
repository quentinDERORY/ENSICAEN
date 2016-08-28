#-------------------------------------------------
#
# Project created by QtCreator 2015-03-04T14:29:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tp4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    docwidget.cpp \
    vue.cpp \
    stat.cpp

HEADERS  += mainwindow.h \
    docwidget.h \
    vue.h \
    stat.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resource.qrc
