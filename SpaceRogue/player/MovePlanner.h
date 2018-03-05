#ifndef MOVEPLANNER_H
#define MOVEPLANNER_H

#include <list>
#include <memory>
#include "../general/Alive.h"

/*! Player ������ ���� �������, ��������� ���� �����������.

*/
class MovePlanner
{
public:
    MovePlanner();
    void setAlive(std::list<Alive*> &alive);
    void makeTurn();

private:
    std::list<Alive*> alive;
};

#endif // MOVEPLANNER_H
