#ifndef ITEM_H_
#define ITEM_H_
#include <string>
enum class ItemType
{
    WEAPON,
    ARMOR,
    USEABLE,
    THING
};

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
