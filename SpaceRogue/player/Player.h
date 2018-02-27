#ifndef PLAYER_H
#define PLAYER_H
#include "../general/Alive.h"
#include "MovePlanner.h"
#include <QString>

/**
 * @brief The Player class
 */
class Player
        : public Alive
{
public:
    Player(QString name);
private:
    MovePlanner* movePlanner;
};

#endif // PLAYER_H
