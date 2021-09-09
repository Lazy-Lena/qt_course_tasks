QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += \
    core_units.cpp \
    cpp_units.cpp \
    csharp_units.cpp \
        main.cpp \

HEADERS += \ \
    core_units.h \
    cpp_units.h \
    csharp_units.h

DESTDIR = $$PWD/../out
