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

#endif