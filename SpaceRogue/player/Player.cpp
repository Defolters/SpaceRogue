#include "Player.h"

Player::Player(QString name) : health(20), maxHealth(20)
{

}

void Player::addHealth(int value)
{
    health += value;

    if (health > maxHealth)
    {
        health = maxHealth;
    }
}

void Player::reduceHealth(int value)
{
    health -= value;
}

int Player::getHealth()
{
    return health;
}

bool Player::isDead()
{
    if (health <= 0)
    {
        return true;
    }
    return false;
}
