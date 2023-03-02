#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "Angka.hpp"
#include "Warna.hpp"
using namespace std;

class DeckCard : public Warna, public Angka{
    private:
        // int num;
        // int type;
    public:
        DeckCard();
        DeckCard(int,int);
        ~DeckCard();
        
        int value();        // Perlu dibuat

        void printInfo();

        // Operator overloading
        DeckCard& operator>(DeckCard&);
        DeckCard& operator<(DeckCard&);
        DeckCard& operator==(DeckCard&);
};

#endif