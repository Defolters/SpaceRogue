#ifndef ENEMY_H
#define ENEMY_H
#include "../general/Alive.h"

/*! Объект враг, который сначала случайно появляется на карте, а затем, если 
    видит главного персонажа, начинает преследовать его.

    Обладает следующими свойствами:
    - Выбрасывает предметы после смерти с какой-то вероятностью

*/
class Enemy
    : public Alive
{
public:
    Enemy(const QString &name, int maxHealth, int armor,
          int strength);
    virtual ~Enemy();
};

#endif // ENEMY_H
