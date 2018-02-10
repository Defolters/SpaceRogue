#pragma once
#include "Object.h"

/*! Класс живых: умеют видеть, двигаться, драться и заниматься прочей фигней
    6. Живые (объекты, которые Могут двигаться):
        a) главный персонаж
        b) враги
*/
class Alive abstract
    : public Object
{
public:
    Alive();
    virtual ~Alive();
};

