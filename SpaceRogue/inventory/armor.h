#ifndef ARMOR_H
#define ARMOR_H
#include "equipment.h"

class Armor : public Equipment
{
private:
    int protection;
public:
    Armor(int weight_, std::string name_, int protection_);
    int getProtection() const;
    virtual ~Armor() = default;
};

#endif // ARMOR_H
