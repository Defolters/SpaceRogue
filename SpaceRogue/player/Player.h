#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include "../general/Alive.h"

/**
 * @brief The Player class
 */
class Player
        : public Alive
{
public:
    Player(const QString &name);

private:
};


#endif // PLAYER_H
