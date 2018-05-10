#include <iostream>
#include "inventory.h"
#include "weapongenerator.h"

int inventory_test()
{
    Armor arm = Armor(15, "plate armor", 10);
    Weapon wep = Weapon(5, "sword", 4);
    Inventory *inventory = new Inventory();
    inventory->takeItem(&arm);
    inventory->takeItem(&wep);
    Item* sw = inventory->getItem("sword");
    if (sw != nullptr)
    {
        Weapon* sword = nullptr;
        std::cout << "Got sword as Item*" << std::endl;
        std::cout << sw->getName() << std::endl;
        if (sw->getType() == ItemType::WEAPON)
        {
            std::cout << "sw* is WEAPON, casting to Weapon*" << std::endl;
            sword = static_cast<Weapon*>(sw);
            if (sword != nullptr)
            {
                std::cout << sword->getAttack() << " attack" << std::endl;
            }
        }
    }
    std::cout << "equipped armor: " << inventory->getEquippedArmor()->getName() << std::endl;
    Item* ar = inventory->getItem("plate armor");
    if (ar!= nullptr)
    {
        Armor* plt = static_cast<Armor*>(ar);
        std::cout << "have plate armor" << std::endl;
        std::cout << plt->getName() << std::endl;
        std::cout << plt->getProtection() << " protection" << std::endl;
        if (inventory->equip("plate armor"))
        {
            std::cout << "equipped it" <<std::endl;
        }
    }
    std::cout << "equipped armor: " << inventory->getEquippedArmor()->getName() << std::endl;
    inventory->drop("plate armor");
    ar = inventory->getItem("plate armor");
    if (ar == nullptr)
    {
        std::cout << "now don't have it" << std::endl;
    }
    std::cout << "equipped armor: " << inventory->getEquippedArmor()->getName() << std::endl;

    //generating 8 level weapon
    Weapon *generated = WeaponGenerator::generateWeapon(8);
    std::cout << "Generated weapon: " << std::endl;
    std::cout << generated->getName() << " " << generated->getAttack() << " " << generated->getWeight() << std::endl;
    
    std::cin.get();
    return 0;
}
