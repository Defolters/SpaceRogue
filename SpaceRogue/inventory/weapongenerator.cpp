#include "weapongenerator.h"
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <fstream>

// linking json library
#include "../libs/json.hpp"
using json = nlohmann::json;

const char* WEAPONS_NOUNS_PATH = "weapon_nouns.json";
const char* WEAPONS_ADJECTIVES_PATH = "weapon_adjectives.json";
std::ifstream noun_stream(WEAPONS_NOUNS_PATH);
json WEAPONS_NOUNS = json::parse(noun_stream);
std::ifstream adj_stream = std::ifstream(WEAPONS_ADJECTIVES_PATH);
json WEAPONS_ADJECTIVES = json::parse(adj_stream);
std::vector<std::string> general_names = WEAPONS_NOUNS["general"];
std::vector<std::string> general_adjs = WEAPONS_ADJECTIVES["general"];

Weapon WeaponGenerator::generateWeapon(int level)
{
    std::srand(unsigned(std::time(0)));
    int weight = std::rand() % MAX_WEAPON_WEIGHT + 1;
    int attack = (int)round(weight * (level/(LEVEL_DIV*1.0f) + 1) - 1);
    if (attack == 0)
        attack = 1;
    int name_num = std::rand() % general_names.size();
    int adj_num = std::rand() % general_adjs.size();
    return Weapon(weight, general_adjs[adj_num] + " " + general_names[name_num], attack);
}
