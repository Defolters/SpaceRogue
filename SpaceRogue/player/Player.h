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
    virtual Vector2f getAim(Vector2f positionOfPlayer) override {}

private:
};


#endif // PLAYER_H
