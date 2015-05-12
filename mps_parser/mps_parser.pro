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
    inst.cpp \
    stack.cpp \
    controlunit.cpp \
    CPU.cpp

HEADERS += \
    parser.h \
    inst.h \
    Mem_WB.h \
    IDec_Exec.h \
    IExec_Mem.h \
    IF_ID.h \
    ../../../../../../Desktop/regfile.h \
    ../../../../../../Desktop/DataMem.h \
    DataMem.h \
    regfile.h \
    stack.h \
    controlunit.h \
    CPU.h

OTHER_FILES += \
    test.txt
