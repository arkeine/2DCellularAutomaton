#-------------------------------------------------
#
# Project created by QtCreator 2015-04-09T12:15:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2DCellularAutomaton
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    data/cellularautomaton.cpp \
    data/gameoflife/conwaygol.cpp

HEADERS  += mainwindow.h \
    data/cellularautomaton.h \
    data/gameoflife/conwaygol.h

FORMS    +=
