#include "Mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), player(nullptr), map(nullptr), manager(nullptr)
{
    ui->setupUi(this);

    player = new Player();
    // выбор режима (player играет сам или мы управляем)
    player->setMode("itself");
    // выбор уровня персонажа (тупой, обычный, гений)
    player->setLevel("fool");

    // создаем карту и размещаем на ней start point и х кол-во разных штук (зависит от сложности)
    map = new Map();
    // выбор сложности (от этого зависит кол-во врагов, предметов)
    map->setDifficulty("difficult");
    // генерируем карту
    map->generateMap();
    // размещаем игрока в start point
    map->setPlayer(player);
    // создаем менеджер, который будет управлять игровым процессом
    manager = new Manager();
    manager->setMap(map);
    manager->setMainWindow(this);
    // запускаем игру
    manager->start(true, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
