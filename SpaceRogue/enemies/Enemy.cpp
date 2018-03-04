#include "Enemy.h"



Enemy::Enemy(const QString &name, int maxHealth, int armor,
             int strength) : Alive(name, maxHealth, armor, strength)
{
}


Enemy::~Enemy()
{
}
