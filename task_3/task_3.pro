QT += core gui widgets

CONFIG += c++11
CONFIG -= console

SOURCES += \
        abstractdirectorystrategy.cpp \
        directorystatsmainwindow.cpp \
        filestatmodel.cpp \
        groupfilestrategy.cpp \
        listfilestrategy.cpp \
        main.cpp

HEADERS += \
    abstractdirectorystrategy.h \
    directorystatsmainwindow.h \
    filestatmodel.h \
    groupfilestrategy.h \
    listfilestrategy.h

FORMS += \
    directorystatsmainwindow.ui

DESTDIR = $$PWD/../out
