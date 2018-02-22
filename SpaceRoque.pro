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
    SpaceRogue/enemies/Enemy.cpp \
    SpaceRogue/field/Map.cpp \
    SpaceRogue/items/Item.cpp \
    SpaceRogue/main/main.cpp \
    SpaceRogue/general/Alive.cpp \
    SpaceRogue/general/Object.cpp \
    SpaceRogue/general/Manager.cpp \
    SpaceRogue/main/Mainwindow.cpp \
    SpaceRogue/player/Player.cpp \
    SpaceRogue/player/MovePlanner.cpp \
    SpaceRogue/enemies/Drone.cpp

HEADERS += \
    SpaceRogue/enemies/Enemy.h \
    SpaceRogue/field/Map.h \
    SpaceRogue/items/Item.h \
    SpaceRogue/general/Alive.h \
    SpaceRogue/general/Coordinates.h \
    SpaceRogue/general/Headers.h \
    SpaceRogue/general/Object.h \
    SpaceRogue/general/Manager.h \
    SpaceRogue/main/Mainwindow.h \
    SpaceRogue/player/Player.h \
    SpaceRogue/player/MovePlanner.h \
    SpaceRogue/field/Field.h \
    SpaceRogue/enemies/Drone.h

FORMS += \
    SpaceRogue/Mainwindow.ui



LIBS += -LD:/SFML-2.4.1/lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += D:/SFML-2.4.1/include
DEPENDPATH += D:/SFML-2.4.1/include
