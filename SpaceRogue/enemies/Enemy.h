#ifndef ENEMY_H
#define ENEMY_H
#include "../general/Alive.h"

/*! ������ ����, ������� ������� �������� ���������� �� �����, � �����, ���� 
    ����� �������� ���������, �������� ������������ ���.

    �������� ���������� ����������:
    - ����������� �������� ����� ������ � �����-�� ������������

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
