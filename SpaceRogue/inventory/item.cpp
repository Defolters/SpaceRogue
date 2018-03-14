#include "item.h"

Item::Item(int weight_, std::string name_, ItemType type_)
{
    weight = weight_;
    name = name_;
    type = type_;
}

std::string Item::getName() const
{
    return name;
}

ItemType Item::getType() const
{
   return type;
}

int Item::getWeight() const
{
    return weight;
}

std::string Item::toString() const
{
    std::string repr = name;
    return repr;
}
