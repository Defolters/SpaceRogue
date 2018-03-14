#ifndef USEABLE_H
#define USEABLE_H

#include "item.h"

enum class EffectType
{
    HEAL
};

class Effect
{
    EffectType type;
    double amount;
    int duration;
public:
    Effect(EffectType type_, double amount_, int duration_ = 1);

    EffectType getType() const;
    double getAmount() const;
    int getDuration() const;
    virtual ~Effect() = default;
};

class Useable :
        public Item
{
private:
    int effectsNum;
    Effect* effects; //c-array for performance
public:
    Useable(Effect* effects_, int effectsNum_, int weight_, std::string name_);
    virtual ~Useable() = default;
};

#endif // USEABLE_H
