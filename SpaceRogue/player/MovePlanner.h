#ifndef MOVEPLANNER_H
#define MOVEPLANNER_H

#include <list>
#include <memory>
#include "../general/Alive.h"

/*! Player думает этим классом, планирует свое направление.

*/
class MovePlanner
{
public:
    MovePlanner();
    void setAlive(std::list<std::shared_ptr<Alive> > &alive);
    void makeTurn();

private:
    std::list<std::shared_ptr<Alive> > alive;
};

#endif // MOVEPLANNER_H
