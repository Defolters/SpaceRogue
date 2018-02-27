#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <QEvent>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), player(nullptr), map(nullptr), manager(nullptr)
{
    ui->setupUi(this);
    ui->widget->installEventFilter(this);
    ui->plainTextEdit->setReadOnly(true);

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
    if (obj == ui->widget) {
            if (event->type() == QEvent::KeyPress) {
                QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

                qDebug() << "Key pressed: " << keyEvent->key();
                QString key;

                if (keyEvent->key() == 16777236)
                {
                    key = "Right";
                }
                else if (keyEvent->key() == 16777234)
                {
                    key = "Left";
                }
                else if (keyEvent->key() == 16777235)
                {
                    key = "Up";
                }
                else if (keyEvent->key() == 16777237)
                {
                    key = "Down";
                }
                else
                {
                    key = QString::number(keyEvent->key());
                }

                addLogMessage(key + " key pressed.");
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

void MainWindow::addLogMessage(const QString &text)
{
    ui->plainTextEdit->appendPlainText(text);
    ui->plainTextEdit->verticalScrollBar()->setValue(ui->plainTextEdit->verticalScrollBar()->maximum());

}
