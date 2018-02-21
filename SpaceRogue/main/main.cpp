// SpaceRogue.cpp : Defines the entry point for the console application.
#include "Mainwindow.h"
#include <QApplication>

int main()
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
