#include "Mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), player(nullptr), map(nullptr), manager(nullptr)
{
    ui->setupUi(this);

    player = new Player();
    // ����� ������ (player ������ ��� ��� �� ���������)
    player->setMode("itself");
    // ����� ������ ��������� (�����, �������, �����)
    player->setLevel("fool");

    // ������� ����� � ��������� �� ��� start point � � ���-�� ������ ���� (������� �� ���������)
    map = new Map();
    // ����� ��������� (�� ����� ������� ���-�� ������, ���������)
    map->setDifficulty("difficult");
    // ���������� �����
    map->generateMap();
    // ��������� ������ � start point
    map->setPlayer(player);
    // ������� ��������, ������� ����� ��������� ������� ���������
    manager = new Manager();
    manager->setMap(map);
    manager->setMainWindow(this);
    // ��������� ����
    manager->start(true, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
