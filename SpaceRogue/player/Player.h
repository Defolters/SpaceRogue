#ifndef PLAYER_H
#define PLAYER_H
#include "../general/Alive.h"
#include "MovePlanner.h"
/*! ����� player
 *
*/
class Player
        : public Alive
{
public:
    Player();
private:
    MovePlanner* movePlanner;
};

#endif // PLAYER_H
