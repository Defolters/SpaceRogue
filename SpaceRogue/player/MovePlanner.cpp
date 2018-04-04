#include "MovePlanner.h"
#include <limits>

MovePlanner::MovePlanner()
{

}

void MovePlanner::setAlive(std::list<Alive *> &alive)
{
    this->alive = alive;
}

void MovePlanner::makeTurn()
{
    /*for (auto creature : alive)
    {
        // analyze place, make movement
    }*/

}

bool MovePlanner::findWay(Coordinate from, Coordinate to, int** level)
{
    // failure if starting or ending it the wall
    if (level[from.x][from.y] == 1)
        return false;
    if (level[to.x][to.y] == 1)
        return false;

    // creating a work copy of the map with only two values
    int** plevel = new int*[x];
    for(int i = 0; i < x; ++i)
        plevel[i] = new int[y];
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if (level[i][j] == 1)
                plevel[i][j] = std::numeric_limits<int>::max();
            else
                plevel[i][j] = std::numeric_limits<int>::min();
        }
    }
    
    // seeting up start
    int d = 0;
    plevel[from.x][from.y] = d;
    // nesting time
    do {
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
            {
                if (plevel[i][j] == d)
                    for (int dX = -1; dX < 2; dX++)
                        for (int dY = -1; dY < 2; dY++)
                            if (dX == 0 || dY == 0)
                            {
                                if (i+dX < x && i+dX >= 0 && j+dY < y && j+dY >= 0)
                                    if (plevel[i+dX][j+dY] == std::numeric_limits<int>::min())
                                        plevel[i+dX][j+dY] = d+1;
                            }
            }
        d++;
    } while (plevel[to.x][to.y] == std::numeric_limits<int>::min());
    
    // reversing path
    int coorX = to.x;
    int coorY = to.y;
    int val = plevel[to.x][to.y];
    Way thisTurn;
    while (coorX != from.x || coorY != from.y)
    {
        int dX;
        int dY;
        for (dX = -1; dX < 2; dX++)
            for (dY = -1; dY < 2; dY++)
                if (dX == 0 || dY == 0)
                {
                    if (coorX+dX < x && coorX+dX >= 0 && coorY+dY < y && coorY+dY >= 0)
                        if (plevel[coorX+dX][coorY+dY] == val - 1)
                        {
                            // moves are inverted because we start from the end
                            if (dX == 1)
                                thisTurn = Way::UP;
                            if (dX == -1)
                                thisTurn = Way::DOWN;
                            if (dY == 1)
                                thisTurn = Way::LEFT;
                            if (dY == -1)
                                thisTurn = Way::RIGHT;
                            goto next;// break through 2 FORs
                        }
                }
    next:
        // adding move to the PATH list
        path.push_front(thisTurn);
        coorX+=dX;
        coorY+=dY;
        val--;
    }
    // success
    return true;
}
