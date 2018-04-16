#include "inventory.h"
#include <algorithm>

Weapon fists = Weapon(0, "fists", 1);
Armor shirt = Armor(0, "shirt", 0);



int Inventory::itemCount() const
{
    return items.size();
}

Inventory::Inventory(QObject *parent)
{

}

std::list<Item*>& Inventory::getItems()
{
    return items;
}

Item* Inventory::getItem(std::string name)
{

    std::list<Item*>::iterator item = items.begin();
    while (item != items.end())
    {
        if ((*item)->getName() == name)
            return *item;
        item++;
    }
    return nullptr;
}

bool Inventory::drop(std::string name)
{
    auto toDrop = std::find_if(items.begin(), items.end(),
                               [name](Item* comp)
                               { if (comp->getName() == name) return true;
                                 else return false;
                               });
    if (toDrop == items.end())
        return false;
    if (*toDrop == equippedArmor)
        equippedArmor = &shirt;
    if (*toDrop == equippedWeapon)
        equippedWeapon = &fists;
    items.erase(toDrop);
    delete *toDrop;
    //delete or place on a map?
    return true;
}

void Inventory::takeItem(Item* item_)
{
    emit redrawInventory();
    items.push_back(item_);
}

int Inventory::totallWeight() const
{
    int weight = 0;
    for (Item* item : items)
    {
        weight += item->getWeight();
    }
    return weight;
}

bool Inventory::equip(std::string name)
{
    Item* toEquip = getItem(name);
    if (toEquip != nullptr)
    {
        ItemType type = toEquip->getType();
        switch (type)
        {
        case ItemType::ARMOR:
            equippedArmor = static_cast<Armor*>(toEquip);
            break;
        case ItemType::WEAPON:
            equippedWeapon = static_cast<Weapon*>(toEquip);
            break;
        default:
            return false;
        }
        return true;
    }
    return false;
}

Armor* Inventory::getEquippedArmor()
{
    return equippedArmor;
}

Weapon* Inventory::getEquippedWeapon()
{
    return equippedWeapon;
}
