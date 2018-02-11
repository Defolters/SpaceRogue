#-------------------------------------------------
#
# Project created by QtCreator 2018-02-11T13:53:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpaceRoqueQT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        mainwindow.cpp \
    SpaceRogue/enemies/Enemy.cpp \
    SpaceRogue/field/Map.cpp \
    SpaceRogue/items/Item.cpp \
    SpaceRogue/main/main.cpp \
    SpaceRogue/main/mainwindow.cpp \
    SpaceRogue/Alive.cpp \
    SpaceRogue/Object.cpp \
    SpaceRogue/SpaceRogue.cpp

HEADERS += \
        mainwindow.h \
    SpaceRogue/enemies/Enemy.h \
    SpaceRogue/field/Map.h \
    SpaceRogue/items/Item.h \
    SpaceRogue/main/mainwindow.h \
    SpaceRogue/Alive.h \
    SpaceRogue/Object.h

FORMS += \
    SpaceRogue/mainwindow.ui
