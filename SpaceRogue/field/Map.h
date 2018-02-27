#pragma once
#include <array>
#include "DungeonGeneration.hpp"
//! �����, ������� �������� ����� ���������. � ����� field ��� �� ����� ���� ��������� ������ ��� ��������� ����� � ����..
// ��� � ��� ����� ����������? ����������� �������/�������?
static const int WIDTH = 50;
static const int HEIGHT = 50;
class Map
{
public:
    Map();
    virtual ~Map();
    void setDifficulty();
    void generateMap();
    void setPlayer();
    int getWidth();
    int getHeight();
    int **getLevel();
private:
    DunGen::Map *mapCreator;
    std::array<std::array<int, WIDTH>, HEIGHT> arr; //!< data structure that contains map (4 width, 3 height)
    //!< data with all objects
    //!< data with alive objects
};

/*
http://pcg.wikidot.com/pcg-algorithm:dungeon-generation
http://pcg.wikidot.com/
http://www.gamedev.ru/code/articles/levelgen1
https://www.rockpapershotgun.com/2015/07/28/how-do-roguelikes-generate-levels/
https://habrahabr.ru/post/275727/
*/
