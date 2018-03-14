#ifndef WEAPON_H
#define WEAPON_H
#include "equipment.h"

class Weapon : public Equipment
{
    int attack;
public:
    Weapon(int weight_, std::string name_, int attack_);
    int getAttack() const;
    virtual ~Weapon() = default;
};

#endif // WEAPON_H
