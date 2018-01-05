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
    passwordform.cpp \
    src/bits.cpp \
    src/deSteg.cpp \
    src/file.cpp \
    src/format.cpp \
    src/lodepng.cpp \
    src/steg.cpp \
    src/sha_256.cpp

HEADERS  += mainwindow.h \
    passwordform.h \
    src/headers/bits.h \
    src/headers/deSteg.h \
    src/headers/file.h \
    src/headers/format.h \
    src/headers/lodepng.h \
    src/headers/sha_256.h \
    src/headers/steg.h

FORMS    += mainwindow.ui \
    passwordform.ui

DISTFILES += \
    src/output.txt \
    src/Makefile
