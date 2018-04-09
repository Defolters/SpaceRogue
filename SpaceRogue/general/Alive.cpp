#include "Alive.h"



Alive::Alive(const QString &name, int maxHealth, int armor,
             int strength) : name(name), maxHealth(maxHealth),
    health(maxHealth), armor(armor), strength(strength)
{
}


Alive::~Alive()
{
}

void Alive::addHealth(int value)
{
    health += value;

    if (health > maxHealth)
    {
        health = maxHealth;
    }
}

void Alive::reduceHealth(int value)
{
    health -= value;
}

int Alive::getHealth()
{
    return health;
}

int Alive::getStrength()
{
    return strength;
}

bool Alive::isDead()
{
    if (health <= 0)
    {
        return true;
    }
    return false;
}

QString Alive::getName()
{
    return name;
}

void Alive::setAim(Vector2f aim)
{
    this->aim = aim;
}
