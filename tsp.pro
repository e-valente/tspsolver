TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bestfirst.cpp \
    hillclimbing.cpp \
    beamsearch.cpp

HEADERS += \
    bestfirst \
    bestfirst.h \
    hillclimbing.h \
    beamsearch.h

