#include "Object.h"



Object::Object()
{
}


Object::~Object()
{
}

Vector2f Object::getPosition()
{
    return this->position;
}

void Object::setPosition(Vector2f pos)
{
    this->position = pos;
}
