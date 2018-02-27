// SpaceRogue.cpp : Defines the entry point for the console application.
#include "../gui/MainWindow.h"

#include <QApplication>
#include <QStyleFactory>
#include <QFont>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
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

    int id = QFontDatabase::addApplicationFont("FAIRFAX.TTF"); //import from debug folder
    QFont font("Fairfax", 14);
    QApplication::setFont(font);

    MainWindow w;
    w.show();

    return a.exec();
}
