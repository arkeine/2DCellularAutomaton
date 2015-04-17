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
    data/gameoflife/conwaygol.cpp \
    gui/gameoflife/widgetgameoflife.cpp \
    gui/widgetdrawgrid.cpp \
    gui/widgetsquarecells.cpp \
    gui/widgetgridcontroler.cpp \
    data/rock-paper-scissors/rockpaperscisors.cpp \
    gui/rock-paper-scissors/widgetrockpaperscisors.cpp

HEADERS  += mainwindow.h \
    data/cellularautomaton.h \
    data/gameoflife/conwaygol.h \
    gui/gameoflife/widgetgameoflife.h \
    gui/widgetdrawgrid.h \
    gui/widgetsquarecells.h \
    gui/widgetgridcontroler.h \
    data/rock-paper-scissors/rockpaperscisors.h \
    gui/rock-paper-scissors/widgetrockpaperscisors.h

FORMS    +=

RESOURCES +=

OTHER_FILES += \
    resources/down-button.svg \
    resources/up-button.svg
