#ifndef MOVEPLANNER_H
#define MOVEPLANNER_H

#include <list>
#include <memory>
#include "../general/Alive.h"
#include "../field/DungeonGeneration.hpp"
#include <QList>

enum class Way {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Coordinate {
    int x;
    int y;
    Coordinate(int x_, int y_) {
        x = x_;
        y = y_;
    }
};

/*! Player думает этим классом, планирует свое направление.

*/
class MovePlanner
{
public:
    MovePlanner();
    void setAlive(std::list<Alive*> &alive);
    void makeTurn();
    
    QList<Way> findWay(Vector2f from, Vector2f to, int** level, int x, int y);
private:
    std::list<Way> path = std::list<Way>();
    std::list<Alive*> alive;
};

#endif // MOVEPLANNER_H
