#include "Player.h"

Player::Player(const QString &name) : Alive(name, 20, 0, 1)
{
    inventory = new Inventory();
}

void Player::reduceHealth(int value)
{
    // armor soaks up some damage
    health -= (int)((value*1.0f) * ((100 - inventory->getEquippedArmor()->getProtection()) / 100.0f));
}

Inventory* Player::getInventory()
{
    return inventory;
}
