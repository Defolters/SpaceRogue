#include "weapon.h"

Weapon::Weapon(int weight_, std::string name_, int attack_)
    : Equipment(weight_, name_, ItemType::WEAPON)
{
    attack = attack_;
}

int Weapon::getAttack() const
{
    return attack;
}
