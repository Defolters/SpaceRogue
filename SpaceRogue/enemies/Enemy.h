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
    virtual Vector2f getAim(Vector2f positionOfPlayer) override;
};

#endif // ENEMY_H
