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
    parser.cpp \
    stack.cpp \
    cpu.cpp \
    controlunit.cpp

HEADERS  += mainwindow.h \
    highlighter.h \
    parser.h \
    instruction.h \
    stack.h \
    regfile.h \
    datamem.h \
    if_id.h \
    idec_exec.h \
    iexec_mem.h \
    mem_wb.h \
    cpu.h \
    controlunit.h

FORMS    += mainwindow.ui

RC_FILE = mpsimulator.rc

RESOURCES = icons.qrc
