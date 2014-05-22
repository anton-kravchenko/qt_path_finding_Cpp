#-------------------------------------------------
#
# Project created by QtCreator 2014-03-09T22:27:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = find_shortest_way
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    choose_buttons.cpp \
    matrix.cpp \
    connector.cpp \
    findway.cpp \
    item.cpp \
    findastarway.cpp \
    images.cpp

HEADERS  += widget.h \
    choose_buttons.h \
    surface_states.h \
    matrix.h \
    connector.h \
    findway.h \
    item.h \
    findastarway.h \
    images.h

FORMS    += widget.ui \
    choose_buttons.ui

RESOURCES += \
    pixmaps.qrc
