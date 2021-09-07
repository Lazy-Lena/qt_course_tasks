QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += \
        abstractcompany.cpp \
        cannabisgrowingcompany.cpp \
        companyregistry.cpp \
        gamingcompany.cpp \
        main.cpp \
        russianbankcompany.cpp

DESTDIR = $$PWD/../out

HEADERS += \
    abstractcompany.h \
    cannabisgrowingcompany.h \
    companyregistry.h \
    gamingcompany.h \
    russianbankcompany.h
