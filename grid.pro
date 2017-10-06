#-------------------------------------------------
#
# Project created by QtCreator 2017-10-06T09:50:32
#
#-------------------------------------------------

QT       += opengl core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = grid
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    glwindow.cpp

HEADERS  += window.h \
    glwindow.h

FORMS    += window.ui
