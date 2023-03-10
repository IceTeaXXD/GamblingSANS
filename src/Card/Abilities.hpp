#ifndef ABILITIES_HPP
#define ABILITIES_HPP

#include "AbilityCard.hpp"

#include <iostream>
using namespace std;

class REROLL: public AbilityCard
{
    public:
        //Re-Roll, membuang 2 kartu dari main deck yang dimiliki oleh diri sendiri dan mengambil ulang 2 kartu.
        REROLL();
        // void use(DeckCard* gameManager,DeckCard* PlayerCard);
        // void use(CardCollection<DeckCard>* deck, CardCollection<DeckCard>* game, int i);
        void printInfo();
};

class Quadruple: public AbilityCard
{
    public:
        //Quadruple, sama seperti aksi double hanya saja multipliernya menjadi 4x.
        Quadruple();
        // void use(int*);
        void printInfo();
};

class Quarter: public AbilityCard
{
    public:
        //Quarter, sama seperti aksi half hanya saja multipliernya menjadi 0.25x.
        Quarter();
        // void use(int*);
        void printInfo();
};

class ReverseDirection: public AbilityCard
{
    public :
        ReverseDirection();
        //ini perlu queue buat nentuin urutan
        // void use(ArrOfPlayer*, int);
        void printInfo();
};

class SwapCard: public AbilityCard
{
    //Kalau ngerjain swab sekalian di switch karena mirip
    public :
        SwapCard();
        // void use(Player*, Player*);
        void printInfo();
};
class Switch: public AbilityCard
{
    public :
        Switch();
        // void use(Player*, Player*);
        void printInfo();
};
class Abilityless : public AbilityCard
{
    public :
        // Abilityless(Player*);
        Abilityless();
        // void use();
        void printInfo();
};

#endif