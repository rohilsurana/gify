#-------------------------------------------------
#
# Project created by QtCreator 2014-07-10T20:25:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gify
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mylabel.cpp

HEADERS  += mainwindow.h \
    mylabel.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

RC_FILE += resources.rc
