#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include "../general/Alive.h"
#include "../inventory/inventory.h"

/**
 * @brief The Player class
 */
class Player
        : public Alive
{
public:
    virtual void reduceHealth(int value) override;
    Inventory* getInventory();
    Player(const QString &name);

private:
    Inventory* inventory;
};


#endif // PLAYER_H
