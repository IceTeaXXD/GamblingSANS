#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Warna{
    private:
        /* Type 
        1. Hijau
        2. Biru
        3. Kuning
        4. Merah */
        int type;
    public:
        void setWarna(string);
        int getType();
        Warna(int);
        Warna();
};

class Angka{
    private:
        int num;
    public:
        void setNum(int);
        int getNum();
        Angka(int);
        Angka();
};

class DeckCard : public Warna, public Angka{
    private:
        // int num;
        // int type;
    public:
        DeckCard();
        DeckCard(int,int);
        ~DeckCard();
        
        void printInfo();
};

class DeckCardCollection{
    private:
        vector<DeckCard> buffer;
    public:
        DeckCardCollection();
        void TableCards();
        DeckCardCollection(int);
        ~DeckCardCollection();
        DeckCard getCard(int);
        DeckCard* takeCard();
        void setCard(DeckCard&);
        void operator+(DeckCard&);
};

#endif