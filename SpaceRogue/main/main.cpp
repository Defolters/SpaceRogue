// SpaceRogue.cpp : Defines the entry point for the console application.
#include "../gui/Mainwindow.h"
#include <QApplication>
#include <QFrame>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    /*QApplication App(argc, argv);

        // Create the main frame
        QFrame* MainFrame = new QFrame;
        MainFrame->setWindowTitle("Qt SFML");
        MainFrame->resize(400, 400);
        MainFrame->show();

        // Create a SFML view inside the main frame
        MyCanvas* SFMLView = new MyCanvas(MainFrame, QPoint(20, 20), QSize(360, 360));
        SFMLView->show();

        return App.exec();*/
}
