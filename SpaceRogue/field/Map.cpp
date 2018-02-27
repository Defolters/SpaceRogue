#include "Map.h"



Map::Map(int difficulty) :
    mapCreator(new DunGen::Map(MAP_WIDTH,MAP_HEIGHT)),
    difficulty(difficulty)
{
    onInit();
}


Map::~Map()
{
}

void Map::setPlayer(Player *player)
{

}

void Map::generateLevel()
{
    level = mapCreator->generateLevel(100,3,10);
}

int Map::getWidth()
{
    return MAP_WIDTH;
}

int Map::getHeight()
{
    return MAP_HEIGHT;
}

int **Map::getLevel()
{
    return level;
}

void Map::onInit()
{
    generateLevel();
    //create level
    // create enemy
    // create items
}
