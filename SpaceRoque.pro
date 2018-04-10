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
    SpaceRogue/main/main.cpp \
    SpaceRogue/general/Alive.cpp \
    SpaceRogue/general/Object.cpp \
    SpaceRogue/general/Manager.cpp \
    SpaceRogue/player/Player.cpp \
    SpaceRogue/player/MovePlanner.cpp \
    SpaceRogue/enemies/Drone.cpp \
    SpaceRogue/gui/QSFMLWidget.cpp \
    SpaceRogue/gui/SFMLCanvas.cpp \
    SpaceRogue/gui/MainWindow.cpp \
    SpaceRogue/inventory/armor.cpp \
    SpaceRogue/inventory/equipment.cpp \
    SpaceRogue/inventory/inventory.cpp \
    SpaceRogue/inventory/item.cpp \
    SpaceRogue/inventory/useable.cpp \
    SpaceRogue/inventory/weapon.cpp \
    SpaceRogue/inventory/weapongenerator.cpp

HEADERS += \
    SpaceRogue/enemies/Enemy.h \
    SpaceRogue/field/Map.h \
    SpaceRogue/general/Alive.h \
    SpaceRogue/general/Coordinates.h \
    SpaceRogue/general/Headers.h \
    SpaceRogue/general/Object.h \
    SpaceRogue/general/Manager.h \
    SpaceRogue/player/Player.h \
    SpaceRogue/player/MovePlanner.h \
    SpaceRogue/field/Field.h \
    SpaceRogue/enemies/Drone.h \
    SpaceRogue/gui/QSFMLWidget.h \
    SpaceRogue/gui/SFMLCanvas.h \
    SpaceRogue/field/DungeonGeneration.hpp \
    SpaceRogue/gui/MainWindow.h \
    SpaceRogue/field/FoV.hpp \
    SpaceRogue/inventory/armor.h \
    SpaceRogue/inventory/equipment.h \
    SpaceRogue/inventory/inventory.h \
    SpaceRogue/inventory/item.h \
    SpaceRogue/inventory/useable.h \
    SpaceRogue/inventory/weapon.h \
    SpaceRogue/inventory/weapongenerator.h \
    SpaceRogue/libs/json.hpp

FORMS += \
    SpaceRogue/gui/MainWindow.ui



#LIBS += -LD:/SFML-2.4.1/lib

#CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-audio -lsfml-network -lsfml-main -lsfml-window -lsfml-system
#CONFIG(debug, debug|release): LIBS += -lsfml-graphics-d -lsfml-audio-d -lsfml-network-d -lsfml-main-d -lsfml-window-d -lsfml-system-d

#INCLUDEPATH += D:/SFML-2.4.1/include
#DEPENDPATH += D:/SFML-2.4.1/include
win32:CONFIG(release, debug|release): LIBS += -LC:/SFML-2.4.2/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/SFML-2.4.2/lib/ -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
else:unix: LIBS += -LC:/SFML-2.4.2/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += C:/SFML-2.4.2/include
DEPENDPATH += C:/SFML-2.4.2/include

DISTFILES += \
    README.md \
    ToDo.md

