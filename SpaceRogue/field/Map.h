#pragma once
#include <memory>
#include <list>

#include "DungeonGeneration.hpp"
#include "../player/Player.h"
#include "../general/Alive.h"

//! �����, ������� �������� ����� ���������. � ����� field ��� �� ����� ���� ��������� ������ ��� ��������� ����� � ����..
// ��� � ��� ����� ����������? ����������� �������/�������?
static const int MAP_WIDTH = 31;
static const int MAP_HEIGHT = 31;

/**
 * @brief The Map class
 * Size of level is constant
 */
class Map
{

public:
    Map(int difficulty);
    virtual ~Map();

    //! ����� ���������. ������ �� ���������� �������� � ���������.
    //! ����� ������� �� �������� ����, ����� ����� ������ ������������������?
    void setDifficulty(int difficulty);

    // ��� �������� shared_ptr?
    void setPlayer(Player* player);
    void generateLevel();

    int getWidth();

    int getHeight();

    int** getLevel();

private:
    void onInit();



    DunGen::Map *mapCreator;
    //! data structure that contains map (4 width, 3 height)
    int **level;
    //! data with all objects
    std::list<std::shared_ptr<Object>> objects;
    //! data with alive objects
    std::list<std::shared_ptr<Alive>> alive;
    int difficulty;
};
