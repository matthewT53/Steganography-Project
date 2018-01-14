#-------------------------------------------------
#
# Project created by QtCreator 2017-04-21T17:16:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HideMySh!t
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    passwordform.cpp \
    src/bits.cpp \
    src/format.cpp \
    src/lodepng.cpp \
    src/steg.cpp \
    src/bin_file.cpp \
    src/bmp_file.cpp \
    src/de_steg.cpp \
    src/png_file.cpp \
    src/steg_file.cpp \
    src/steg_helper.cpp

HEADERS  += mainwindow.h \
    passwordform.h \
    src/headers/bits.h \
    src/headers/format.h \
    src/headers/lodepng.h \
    src/headers/steg.h \
    src/headers/bin_file.h \
    src/headers/bmp_file.h \
    src/headers/de_steg.h \
    src/headers/png_file.h \
    src/headers/steg_file.h \
    src/headers/steg_helper.h

FORMS    += mainwindow.ui \
    passwordform.ui

DISTFILES += \
    src/output.txt \
    src/Makefile
