#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <QEvent>
#include <QScrollBar>
#include <QTableWidgetItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), map(nullptr), manager(nullptr)
{
    ui->setupUi(this);
    ui->sfmlWidget->installEventFilter(this);
    ui->plainTextEdit->setReadOnly(true);

    // выбор режима (player играет сам или мы управляем)
//    player->setMode("itself");
    // выбор уровня персонажа (тупой, обычный, гений)
//    player->setLevel("fool");

    // создаем карту и размещаем на ней start point и х кол-во разных штук (зависит от сложности)
    map = new Map(0);


    // выбор сложности (от этого зависит кол-во врагов, предметов)
//    map->setDifficulty(1);
    // размещаем игрока в start point
    //map->setPlayer(player.get());
    map->generateLevel();
    ui->sfmlWidget->setMap(map);
    // создаем менеджер, который будет управлять игровым процессом
    /*
    цель игрока - добраться до выхода на следующий уровень
    если выход в поле видимости, то движемся к нему
    по пути можно забрать предмет
    по пути можно избегать/убивать врагов

    игрок двигается по видимым комантам (виден путь, соединяющий их)
    то есть он направляется в комнаты, мимо которых проходил.
    в комнаты, мимо которых он не ходил, идти не может

    ближайшая комната: комната, путь к которой наименьший (функция поиска пути, размер меньше)
    установить цель
    двигаться, пока цель не достигнута? (избегать врагов и подбирать предметы по пути?)

    лист пройденных комнат
    лист комнат, которые видел, лист комнат, которые рядом
    идем в комнаты, сортированные по дальности (идем в ближайшую),
    в которыееще не ходили

    manager->start(true, 0);
    запускает медленную итерацию, в которой персонаж делает ОДНО действие
    надевает/использует/бьет/идет


    */
    //map->start(true, 1);
//    manager = new Manager();
//    manager->setMap(map);
//    manager->setMainWindow(this);
    // запускаем игру
//    manager->start(true, 0);
//    connect(map, SIGNAL(updateWindow()),
//            this, SLOT(repaint()));
    connect(map, SIGNAL(newEvent(QString)),
            this, SLOT(addLogMessage(QString)));
    connect(map, SIGNAL(newLevel()),
            this, SLOT(newLevel()));
    connect(map, SIGNAL(newTurn(int)),
            this, SLOT(newTurn(int)));
    connect(map, SIGNAL(gameOver()),
            this, SLOT(gameOver()));
    connect(map->getPlayer()->getInventory(), SIGNAL(redrawInventory()),
            this, SLOT(redrawInventory()));
    map->moveToThread(map);
    map->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->sfmlWidget) {
            if (event->type() == QEvent::KeyPress) {
                QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

                //qDebug() << "Key pressed: " << keyEvent->key();
                QString key;

                //map->movePlayer(keyEvent->key());
//                map->start(true, 1);
                //map->makeTurn();
//                ui->sfmlWidget->onUpdate();
                ui->health->setText(QString::number(map->getPlayer()->getHealth()));

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

                //addLogMessage(key + " key pressed.");
                return true;

            } else {
                return false;
            }
        } else {
            // pass the event on to the parent class
            return QMainWindow::eventFilter(obj, event);
    }
}

void MainWindow::redrawInventory()
{
    Inventory* inv = map->getPlayer()->getInventory();
    auto invWidget = ui->inventoryWidget;
    int itemCount = inv->itemCount();
    qDebug() << "items: " << itemCount;
    if (invWidget->rowCount() < itemCount)
    {
        for (int i = invWidget->rowCount(); i<itemCount; i++)
        {
            invWidget->insertRow(i);
        }
    }
    if (invWidget->rowCount() > itemCount)
    {
        for (int i = invWidget->rowCount(); i>itemCount; i--)
        {
            invWidget->removeRow(i);
        }
    }
    invWidget->clearContents();
    auto items = inv->getItems();
    auto item = items.begin();
    for (int i = 0; i < itemCount; i++)
    {
        invWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(TYPENAMES[(int)(*item)->getType()])));
        invWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString((*item)->getName())));
        if ((*item)->getType() == ItemType::THING)
        {
            invWidget->setItem(i,2,new QTableWidgetItem("none"));
        }
        else
        {
            int efficency = 0;
            switch ((*item)->getType())
            {
                case ItemType::ARMOR:
                    efficency = ((Armor*)(*item))->getProtection();
                break;
                case ItemType::WEAPON:
                    efficency = ((Weapon*)(*item))->getAttack();
                break;
                    //TODO useable
            }
            invWidget->setItem(i,2,new QTableWidgetItem(QString::number(efficency)));
        }
        invWidget->setItem(i,3,new QTableWidgetItem(QString::number((*item)->getWeight())));
        item++;
    }
}

void MainWindow::on_generateLevel_clicked()
{
    newLevel();
}

void MainWindow::addLogMessage(const QString &text)
{
    ui->plainTextEdit->appendPlainText(text);
    ui->plainTextEdit->verticalScrollBar()->setValue(ui->plainTextEdit->verticalScrollBar()->maximum());
}

void MainWindow::newLevel()
{
    map->generateLevel();
    ui->sfmlWidget->setMap(map);
    ui->level->setText(QString::number(map->getLevelNumber()));
    redrawInventory();
}

void MainWindow::newTurn(int turn)
{
    ui->turn->setText(QString::number(turn));
    ui->health->setText(QString::number(map->getPlayer()->getHealth()));
}

void MainWindow::gameOver()
{
    ui->sfmlWidget->endOfGame();
}
