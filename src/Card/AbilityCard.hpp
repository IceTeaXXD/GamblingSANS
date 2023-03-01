#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP
#include <iostream>

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
        void use(DeckCard* gameManager,DeckCard* PlayerCard);
        void use(Card *);
};
class Quadruple : AbilityCard
{
    public:
        //Quadruple, sama seperti aksi double hanya saja multipliernya menjadi 4x.
        Quadruple(int);
        void use(int);
};
class Quarter : AbilityCard
{
    public:
        //Quarter, sama seperti aksi half hanya saja multipliernya menjadi 0.25x.
        Quarter(int);
        void use(int);
};
class ReverseDirection : AbilityCard
{
    public :
        ReverseDirection();
        //ini perlu queue buat nentuin urutan
        void use();
};
class SwapCard : AbilityCard
{
    //Kalau ngerjain swab sekalian di switch karena mirip
    public :
        SwapCard(Player*);
        void use();
};
class Switch : AbilityCard
{
    public :
        Switch(Player*);
        void use();
};
class Abilityless : public AbilityCard
{
    public :
        Abilityless(Player*);
        void use();
};

class AbilityCardCollection{
    private:
        vector<DeckCard> buffer;
    public:
        AbilityCardCollection();
        ~AbilityCardCollection();
        AbilityCard getCard();
};
#endif