#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../field/Map.h"
#include "../general/Manager.h"
#include "../player/Player.h"

namespace Ui {
class MainWindow;
}
/*! Основа программы:
 * содержит в себе главные компоненты
 * запускает всю работу и следит за состоянием, чтобы все это выводить.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    bool eventFilter(QObject *obj, QEvent *event);


private slots:
    void on_generateLevel_clicked();

private:
    void addLogMessage(const QString &text);
    Map* map;  //!<
    Manager* manager;  //!<
    Player* player;  //!<

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

/*
sfml and qt
https://evileg.com/en/post/286/
https://github.com/SFML/SFML/wiki/tutorial:-compile-and-link-sfml-with-qt-creator
https://github.com/SFML/SFML/wiki/Tutorial:-Link-SFML-with-Qt-Creator
https://www.sfml-dev.org/tutorials/1.6/graphics-qt.php
https://www.youtube.com/watch?v=VWvD4mUpyfU
*/
