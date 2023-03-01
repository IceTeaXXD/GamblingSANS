#ifndef KOMBINASI_HPP
#define KOMBINASI_HPP
#include <iostream>
#include "FindValue.hpp"
#include "../Card/DeckCard.hpp"

class Kombinasi : protected FindValue{
    private:
        //0-1 player, sisanya table
        vector<DeckCard> arr;

    public:
        /* Default Constructor */
        Kombinasi();
        ~Kombinasi();
        /* Setter */
        /* Set Kartu dari playerCards dan tableCards*/
        void setCards(DeckCardCollection playerCards, DeckCardCollection tableCards);

        /* Nentuin value kartu untuk kombinasi */
        double value();

        /* Bruteforcing untuk Kombinasi Kartu */
        int getCombination(DeckCard x, DeckCard tc);

        /* Operator overloading buat bandingin value */
        Kombinasi& operator>(Kombinasi&);
        Kombinasi& operator<(Kombinasi&);
        Kombinasi& operator==(Kombinasi&);
        
        /*  Rule:
            - highcard rumusnya ngikutin yg di docs, value = konstanta + 0.3*warna 
            - Pair bernilai 2
            - Two Pair bernilai 4
            - Three Of Kind nilainya 6
            - dst (inc 2)
            - Jadi nanti buat di fungsi yg value tinggal panggil aja ini semua dijumlahin
        */
        double HighCard();
        bool isPair();
        bool isTwoPair();
        bool isThreeOfKind();
        bool isStraight();
        bool isFlush();
        bool isFullHouse();
        bool isFourAKind();
        bool isStraightFlush();
};

#endif
