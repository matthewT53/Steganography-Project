#-------------------------------------------------
#
# Project created by QtCreator 2017-04-21T17:16:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Spyink
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filebrowser.cpp \
    passwordform.cpp

HEADERS  += mainwindow.h \
    filebrowser.h \
    passwordform.h

FORMS    += mainwindow.ui \
    filebrowser.ui \
    passwordform.ui
