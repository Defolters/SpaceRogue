#include "Enemy.h"



Enemy::Enemy(const QString &name, int maxHealth, int armor,
             int strength) : Alive(name, maxHealth, armor, strength)
{
    aim = getPosition();
}


Enemy::~Enemy()
{
}

Vector2f Enemy::getAim(Vector2f positionOfPlayer)
{
    if (sqrt( pow((getPosition().x-positionOfPlayer.x),2) + pow((getPosition().x-positionOfPlayer.x),2)) < 2)
    {
        aim = positionOfPlayer;

    }// if player in distance, move
    return positionOfPlayer;
}
