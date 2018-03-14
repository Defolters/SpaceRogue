#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "item.h"

class Equipment:
        public Item
{
public:
    Equipment(int weight_, std::string name_, ItemType type_);
    virtual ~Equipment() = default;
};

#endif // EQUIPMENT_H
