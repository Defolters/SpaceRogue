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

    void addHealth(int value);
    void reduceHealth(int value);
    int getHealth();
    bool isDead();

private:
    MovePlanner* movePlanner;

    int health;
    const int maxHealth;
    //int hunger; //!< Голод по убийствам
    //int armor;

};

#endif // PLAYER_H
