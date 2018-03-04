#ifndef ALIVE_H
#define ALIVE_H
#include "Object.h"
#include <QString>
/*! ����� �����: ����� ������, ���������, ������� � ���������� ������ ������
    6. ����� (�������, ������� ����� ���������):
        a) ������� ��������
        b) �����
*/
class Alive
    : public Object
{
public:
    Alive(const QString &name, int maxHealth, int armor,
          int strength);
    virtual ~Alive();

    void addHealth(int value);
    void reduceHealth(int value);
    int getHealth();
    int getStrength();
    bool isDead();
    QString getName();

private:
    QString name;
    int health;
    int armor;
    int strength;
    int experience;
    int gold;
    const int maxHealth;
    //int hunger; //!< ����� �� ���������
    //int armor;
};

#endif // ALIVE_H
