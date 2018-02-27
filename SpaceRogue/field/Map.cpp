#include "Map.h"



Map::Map() : mapCreator(new DunGen::Map(31,31))
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
    return mapCreator->generateLevel(100,3,10);
}
