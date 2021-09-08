QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += \
        classunit.cpp \
        main.cpp \
        methodunit.cpp \
        printoperatorunit.cpp \
        unit.cpp

DESTDIR = $$PWD/../out

HEADERS += \
    classunit.h \
    methodunit.h \
    printoperatorunit.h \
    unit.h \
    unitfactory.h
