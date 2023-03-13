#ifndef UNO_ACTION_CARD_HPP
#define UNO_ACTION_CARD_HPP

#include <iostream>
#include <vector>
#include "../GameManager/GameManager.hpp"
#include "Warna.hpp"
#include "AbilityCard.hpp"


class plus2 : public AbilityCard, public Warna
{
    public:
        plus2();
        void use(GameManager*);
};

class wildcard4 : public AbilityCard
{
    public:
        wildcard4();
        void use(GameManager*);
};

class wildcard : public AbilityCard
{
    public:
        wildcard();
        void use(GameManager*);
};

#endif