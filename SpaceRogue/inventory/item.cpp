#include "item.h"

std::array<std::string, 4> TYPENAMES = {"weapon", "armor", "useable", "thing"};

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
