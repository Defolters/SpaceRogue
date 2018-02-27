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
    // ����� ������ (player ������ ��� ��� �� ���������)
//    player->setMode("itself");
    // ����� ������ ��������� (�����, �������, �����)
//    player->setLevel("fool");

    // ������� ����� � ��������� �� ��� start point � � ���-�� ������ ���� (������� �� ���������)
    map = new Map();
    ui->widget->setMap(map);
    // ����� ��������� (�� ����� ������� ���-�� ������, ���������)
//    map->setDifficulty("difficult");
    // ���������� �����
//    map->generateMap();
    // ��������� ������ � start point
//    map->setPlayer(player);
    // ������� ��������, ������� ����� ��������� ������� ���������
    manager = new Manager();
//    manager->setMap(map);
//    manager->setMainWindow(this);
    // ��������� ����
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
