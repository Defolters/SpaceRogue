// SpaceRogue.cpp : Defines the entry point for the console application.
#include "../gui/Mainwindow.h"
#include <QApplication>
#include <QFrame>
#include <QStyleFactory>
#include <QFont>
#include <QFontDatabase>
#include <QDebug>
#include <QDir>
#include "../field/DungeonGeneration.hpp"

int main(int argc, char *argv[])
{
    DunGen::Map mapCreator(30,80);

    mapCreator.generateLevel(20,3,10);
    mapCreator.printLevel();

    mapCreator.generateLevel(30,3,7);
    mapCreator.printLevel();

    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("Fusion"));

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(22,22,22));
    darkPalette.setColor(QPalette::WindowText, Qt::green);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(22,22,22));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::green);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(22,22,22));
    darkPalette.setColor(QPalette::ButtonText, Qt::green);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    a.setPalette(darkPalette);
    a.setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");

    qDebug() << QDir::currentPath();
    int id = QFontDatabase::addApplicationFont("FAIRFAX.TTF"); //import from debug folder
    QFont font("Fairfax", 14);
    QApplication::setFont(font);

    MainWindow w;
    w.show();

    return a.exec();
}
