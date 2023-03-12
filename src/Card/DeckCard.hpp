#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "Angka.hpp"
#include "Warna.hpp"
#include "../Rules/FindValue.hpp"
using namespace std;

class DeckCard : public Warna, public Angka{
    private:
        // int num;
        // int type;
    public:
        DeckCard();
        DeckCard(int,int);
        ~DeckCard();
        

        void printInfo();
        void printType();
        double value();
        // Operator overloading
        bool operator>(DeckCard&);
        bool operator<(DeckCard&);
        bool operator==(DeckCard&);
        bool operator==(const DeckCard&) const; 
};

bool compareAngka(DeckCard c, DeckCard other);
bool compareWarna(DeckCard c, DeckCard other);
bool compareValue(DeckCard c, DeckCard other);

#endif