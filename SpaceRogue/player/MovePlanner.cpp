#include "MovePlanner.h"

MovePlanner::MovePlanner()
{

}

void MovePlanner::setAlive(std::list<std::shared_ptr<Alive> > &alive)
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
