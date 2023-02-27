#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP
#include <iostream>
#include "Card.hpp"
// #include "../Player/Player.hpp"

class AbilityCard : public Card{
    private:
        bool availability;
        // Player owner;
    public:
        AbilityCard(bool);
        bool isAvailable();
        void setNotAvailable();
        // Player getOwner(AbilityCard*);
        virtual void use();
};
class REROLL : AbilityCard
{
    public:
        //Re-Roll, membuang 2 kartu dari main deck yang dimiliki oleh diri sendiri dan mengambil ulang 2 kartu.
        void use(Card*);
};
class Quadruple : AbilityCard
{
    public:
        //Quadruple, sama seperti aksi double hanya saja multipliernya menjadi 4x.
        void use();
};
class Quarter : AbilityCard
{
    public:
        //Quarter, sama seperti aksi half hanya saja multipliernya menjadi 0.25x.
        void use();
};
class ReverseDirection : AbilityCard
{
    public :
        void use();
};
class SwabCard : AbilityCard
{
    public :
        void use();
};
class Switch : AbilityCard
{
    public :
        void use();
};
class Abilityless : public AbilityCard
{
    public :
        void use();
};
#endif