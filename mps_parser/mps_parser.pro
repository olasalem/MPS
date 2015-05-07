#-------------------------------------------------
#
# Project created by QtCreator 2015-05-04T21:09:31
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = mps_parser
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    parser.cpp \
    inst.cpp

HEADERS += \
    parser.h \
    inst.h

OTHER_FILES += \
    test.txt
