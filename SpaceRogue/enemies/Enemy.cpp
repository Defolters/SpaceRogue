#include "Enemy.h"



Enemy::Enemy(const QString &name, int maxHealth, int armor,
             int strength) : Alive(name, maxHealth, armor, strength)
{
}


Enemy::~Enemy()
{
}

Vector2f Enemy::getAim(Vector2f positionOfPlayer)
{
    if (sqrt( pow((getPosition().x-positionOfPlayer.x),2) + pow((getPosition().x-positionOfPlayer.x),2)) < 2)
    {
        return positionOfPlayer;
    }// if player in distance, move
}
