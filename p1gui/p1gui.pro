#-------------------------------------------------
#
# Project created by QtCreator 2013-02-13T00:54:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = p1gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    link.cpp \
    canvas.cpp \
    axis.cpp \
    painter.cpp

HEADERS  += mainwindow.h \
    link.h \
    canvas.h \
    armadillo \
    axis.h \
    painter.h

FORMS    += mainwindow.ui


