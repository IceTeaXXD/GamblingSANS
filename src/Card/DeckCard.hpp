#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include <iostream>
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
};

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
        string getType();
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

#endif