QT += core gui widgets charts

CONFIG += c++11
CONFIG -= console

SOURCES += \
        abstractdirectorystrategy.cpp \
        abstractstatholder.cpp \
        chartupdater.cpp \
        filestatmodel.cpp \
        groupfilestrategy.cpp \
        listfilestrategy.cpp \
        main.cpp \
        statsmainwindow.cpp

HEADERS += \
    abstractdirectorystrategy.h \
    abstractstatholder.h \
    chartupdater.h \
    filestatmodel.h \
    groupfilestrategy.h \
    listfilestrategy.h \
    statsmainwindow.h

FORMS += \
    statsmainwindow.ui

DESTDIR = $$PWD/../out
