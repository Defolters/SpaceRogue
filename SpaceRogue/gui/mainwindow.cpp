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




    player = std::make_shared<Player>("Player One");
    // ����� ������ (player ������ ��� ��� �� ���������)
//    player->setMode("itself");
    // ����� ������ ��������� (�����, �������, �����)
//    player->setLevel("fool");

    // ������� ����� � ��������� �� ��� start point � � ���-�� ������ ���� (������� �� ���������)
    map = std::make_shared<Map>(0);

    ui->widget->setMap(map.get());
    // ����� ��������� (�� ����� ������� ���-�� ������, ���������)
//    map->setDifficulty(1);
    // ��������� ������ � start point
    map->setPlayer(player.get());
    // ������� ��������, ������� ����� ��������� ������� ���������
    manager = std::make_shared<Manager>();
//    manager->setMap(map);
//    manager->setMainWindow(this);
    // ��������� ����
//    manager->start(true, 0);
    connect(map.get(), SIGNAL(newEvent(QString)),
            this, SLOT(addLogMessage(QString)));
    connect(map.get(), SIGNAL(nextLevel(int)),
            this, SLOT(setLevelNumber()));
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
    map->generateLevel();
    ui->widget->setMap(map.get());
}

void MainWindow::addLogMessage(const QString &text)
{
    ui->plainTextEdit->appendPlainText(text);
    ui->plainTextEdit->verticalScrollBar()->setValue(ui->plainTextEdit->verticalScrollBar()->maximum());
}

void MainWindow::setLevelNumber(int levelNumber)
{
    ui->level->setText(QString::number(levelNumber));
}
