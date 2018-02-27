#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <QEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), player(nullptr), map(nullptr), manager(nullptr)
{
    ui->setupUi(this);
    ui->widget->installEventFilter(this);

    player = new Player();
    // выбор режима (player играет сам или мы управляем)
//    player->setMode("itself");
    // выбор уровня персонажа (тупой, обычный, гений)
//    player->setLevel("fool");

    // создаем карту и размещаем на ней start point и х кол-во разных штук (зависит от сложности)
    map = new Map();
    ui->widget->setMap(map);
    // выбор сложности (от этого зависит кол-во врагов, предметов)
//    map->setDifficulty("difficult");
    // генерируем карту
//    map->generateMap();
    // размещаем игрока в start point
//    map->setPlayer(player);
    // создаем менеджер, который будет управлять игровым процессом
    manager = new Manager();
//    manager->setMap(map);
//    manager->setMainWindow(this);
    // запускаем игру
//    manager->start(true, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    //qDebug() << Q_FUNC_INFO;

    if (obj == ui->widget) {
            if (event->type() == QEvent::KeyPress) {
                QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
                qDebug() << "Ate key press" << keyEvent->key();
                return true;
            } else {
                return false;
            }
        } else {
            // pass the event on to the parent class
            return QMainWindow::eventFilter(obj, event);
    }
}

void MainWindow::on_generateLevel_clicked()
{
    ui->widget->setMap(map);
}
