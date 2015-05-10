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
    algo/cellularautomaton.cpp \
    algo/gameoflife/conwaygol.cpp \
    gui/gameoflife/widgetgameoflife.cpp \
    gui/widgetdrawgrid.cpp \
    gui/widgetsquarecells.cpp \
    gui/widgetgridcontroler.cpp \
    algo/rock-paper-scissors/rockpaperscisors.cpp \
    gui/rock-paper-scissors/widgetrockpaperscisors.cpp \
    gui/widgetwellcome.cpp \
    algo/mazesolver/mazesolver.cpp \
    gui/mazesolver/widgetmazesolver.cpp \
    data/cellulararray.cpp \
    data/toriccellulararray.cpp \
    data/bordercellulararray.cpp

HEADERS  += mainwindow.h \
    algo/cellularautomaton.h \
    algo/gameoflife/conwaygol.h \
    gui/gameoflife/widgetgameoflife.h \
    gui/widgetdrawgrid.h \
    gui/widgetsquarecells.h \
    gui/widgetgridcontroler.h \
    algo/rock-paper-scissors/rockpaperscisors.h \
    gui/rock-paper-scissors/widgetrockpaperscisors.h \
    gui/widgetwellcome.h \
    algo/mazesolver/mazesolver.h \
    gui/mazesolver/widgetmazesolver.h \
    data/cellulararray.h \
    data/toriccellulararray.h \
    data/bordercellulararray.h

FORMS    +=

RESOURCES +=

OTHER_FILES += \
    resources/down-button.svg \
    resources/up-button.svg
