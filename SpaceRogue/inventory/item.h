#ifndef ITEM_H_
#define ITEM_H_
#include <string>
#include <array>

enum class ItemType
{
    WEAPON = 0,
    ARMOR,
    USEABLE,
    THING
};

extern std::array<std::string, 4> TYPENAMES;
class Item
{
private:
    int weight;
    std::string name;
    ItemType type;
public:
    Item(int weight_, std::string name_, ItemType type_);
    int getWeight() const;
    std::string getName() const;
    ItemType getType() const;
    std::string toString() const;
    virtual ~Item() = default;
};

#endif /* ITEM_H_ */
