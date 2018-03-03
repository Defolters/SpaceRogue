#include "useable.h"

Effect::Effect(EffectType type_, double amount_, int duration_ /*= 1*/)
{
    type = type_;
    amount = amount_;
    duration = duration_;
}

double Effect::getAmount() const
{
    return amount;
}

int Effect::getDuration() const
{
    return duration;
}

EffectType Effect::getType() const
{
    return type;
}

Useable::Useable(Effect* effects_, int effectsNum_, int weight_, std::string name_)
    : Item(weight_, name_, ItemType::USEABLE)
{
    effectsNum = effectsNum_;
    effects = effects_;
}
