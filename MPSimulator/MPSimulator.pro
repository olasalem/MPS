#-------------------------------------------------
#
# Project created by QtCreator 2015-05-03T09:12:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MPSimulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    highlighter.cpp \
    codeeditor.cpp

HEADERS  += mainwindow.h \
    highlighter.h \
    codeeditor.h

FORMS    += mainwindow.ui

RC_FILE = mpsimulator.rc
