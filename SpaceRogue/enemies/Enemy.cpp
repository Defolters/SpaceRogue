#include "Enemy.h"



Enemy::Enemy(const QString &name, int maxHealth, int armor,
             int strength) : Alive(name, maxHealth, armor, strength)
{
    Alive::setAim(getPosition());
}


Enemy::~Enemy()
{
}

Vector2f Enemy::getAim(Vector2f positionOfPlayer)
{
    if (sqrt( pow((getPosition().x-positionOfPlayer.x),2) + pow((getPosition().y-positionOfPlayer.y),2)) < 4.5)
    {
        Alive::setAim(positionOfPlayer);

    }

    return Alive::getAim(positionOfPlayer);
}
