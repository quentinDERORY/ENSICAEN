#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T14:38:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tp5
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    InvoiceModel.cpp \
    vue.cpp

HEADERS  += mainwindow.h \
    InvoiceModel.h \
    vue.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resource.qrc
