#pragma once
#include <memory>
#include <list>

#include "DungeonGeneration.hpp"
#include "../player/Player.h"
#include "../general/Alive.h"

//! Класс, который содержит карту местности. В папке field так же могут быть служебные классы для генерации карты и проч..
// Что у нас будет местностью? Космический корабль/станция?
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

    //! Выбор сложности. Влияет на количество мностров и предметов.
    //! Можно выбрать из главного меню, тогда карта должна перегенерироваться?
    void setDifficulty(int difficulty);

    // Или аргумент shared_ptr?
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
