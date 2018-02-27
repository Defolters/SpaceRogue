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
