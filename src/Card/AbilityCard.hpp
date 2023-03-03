#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP

#include <iostream>
#include <vector>
#include "../GameManager/GameManager.hpp"

class AbilityCard{
    private:
        bool availability;
    public:
        AbilityCard();
        AbilityCard(bool);
        bool isAvailable();
        void setNotAvailable();
        virtual void use();
};
class REROLL : AbilityCard
{
    public:
        //Re-Roll, membuang 2 kartu dari main deck yang dimiliki oleh diri sendiri dan mengambil ulang 2 kartu.
        REROLL();
        // void use(DeckCard* gameManager,DeckCard* PlayerCard);
        void use(GameManager *game, int i);
};
class Quadruple : AbilityCard
{
    public:
        //Quadruple, sama seperti aksi double hanya saja multipliernya menjadi 4x.
        Quadruple();
        void use(int, GameManager*);
};
class Quarter : AbilityCard
{
    public:
        //Quarter, sama seperti aksi half hanya saja multipliernya menjadi 0.25x.
        Quarter();
        void use(int, GameManager*);
};
class ReverseDirection : AbilityCard
{
    public :
        ReverseDirection();
        //ini perlu queue buat nentuin urutan
        void use(GameManager*);
};
class SwapCard : AbilityCard
{
    //Kalau ngerjain swab sekalian di switch karena mirip
    public :
        SwapCard();
        void use(Player*, Player*);
};
class Switch : AbilityCard
{
    public :
        Switch();
        void use(Player*, Player*);
};
class Abilityless : public AbilityCard
{
    public :
        // Abilityless(Player*);
        void use();
};

class AbilityCardCollection{
    private:
        // vector<DeckCard> buffer;
    public:
        AbilityCardCollection();
        ~AbilityCardCollection();
        AbilityCard getCard();
};
#endif