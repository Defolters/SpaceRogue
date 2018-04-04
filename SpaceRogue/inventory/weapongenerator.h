#ifndef WEAPONGENERATOR_H
#define WEAPONGENERATOR_H
#include "weapon.h"

class WeaponGenerator
{
public:
    static const int MAX_WEAPON_WEIGHT = 10;
    static const int LEVEL_DIV = 15;
    static Weapon generateWeapon(int level);
};

#endif // WEAPONGENERATOR_H
