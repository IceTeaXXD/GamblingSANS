#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
using namespace std;

class Card{
    public:
        Card();
        virtual int getType() const = 0;
};

class DeckCard : Card{
    private:
        int num;
        /* Type 
        1. Hijau
        2. Biru
        3. Kuning
        4. Merah */
        int type;
    public:
        DeckCard(int n);
        ~DeckCard();
        int getNum();
        int getType();
};

class AbilityCard : Card{
    private:
        /* Type
            1. Re-Roll
            2. Quadruple
            3. Quarter
            4. Reverse Direction
            5. Swap Card
            6. Switch
            7. Abilityless
        */
        int type;
    
    public:
        AbilityCard(int type);
        int getType();
};


#endif