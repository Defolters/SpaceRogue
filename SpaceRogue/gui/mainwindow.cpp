#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <QEvent>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), map(nullptr), manager(nullptr)
{
    ui->setupUi(this);
    ui->sfmlWidget->installEventFilter(this);
    ui->plainTextEdit->setReadOnly(true);





    // ����� ������ (player ������ ��� ��� �� ���������)
//    player->setMode("itself");
    // ����� ������ ��������� (�����, �������, �����)
//    player->setLevel("fool");

    // ������� ����� � ��������� �� ��� start point � � ���-�� ������ ���� (������� �� ���������)
    map = new Map(0);


    // ����� ��������� (�� ����� ������� ���-�� ������, ���������)
//    map->setDifficulty(1);
    // ��������� ������ � start point
    //map->setPlayer(player.get());
    map->generateLevel();
    ui->sfmlWidget->setMap(map);
    // ������� ��������, ������� ����� ��������� ������� ���������
    manager = new Manager();
//    manager->setMap(map);
//    manager->setMainWindow(this);
    // ��������� ����
//    manager->start(true, 0);
    connect(map, SIGNAL(newEvent(QString)),
            this, SLOT(addLogMessage(QString)));
    connect(map, SIGNAL(newLevel()),
            this, SLOT(newLevel()));
    connect(map, SIGNAL(newTurn(int)),
            this, SLOT(newTurn(int)));
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
                map->movePlayer(keyEvent->key());
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
}

void MainWindow::newTurn(int turn)
{
    ui->turn->setText(QString::number(turn));
    ui->health->setText(QString::number(map->getPlayer()->getHealth()));
}
