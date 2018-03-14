#include "armor.h"

Armor::Armor(int weight_, std::string name_, int protection_)
    : Equipment(weight_, name_, ItemType::ARMOR)
{
    protection = protection_;
}

int Armor::getProtection() const
{
    return protection;
}
