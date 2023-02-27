#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
using namespace std;

class Card{
    public:
        Card();
        virtual string getType();
        virtual int getNum();
        virtual void printInfo();
};

class DeckCard : public Card{
    private:
        int num;
        /* Type 
        1. Hijau
        2. Biru
        3. Kuning
        4. Merah */
        int type;
    public:
        DeckCard();
        DeckCard(int,int);
        ~DeckCard();
        int getNum();
        string getType();
        void printInfo();
};

#endif