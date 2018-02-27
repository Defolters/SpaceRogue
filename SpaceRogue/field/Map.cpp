#include "Map.h"



Map::Map() : mapCreator(new DunGen::Map(30,30))
{
}


Map::~Map()
{
}

int Map::getWidth()
{
    return mapCreator->getWidth();
}

int Map::getHeight()
{
    return mapCreator->getHeight();
}

int **Map::getLevel()
{
    return mapCreator->generateLevel(5,3,10);
}
