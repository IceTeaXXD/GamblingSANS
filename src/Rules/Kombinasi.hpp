#ifndef KOMBINASI_HPP
#define KOMBINASI_HPP
#include <iostream>
#include <algorithm>
#include "FindValue.hpp"
#include "../Card/DeckCard.hpp"
#include "../Card/DeckCardCollection.hpp"

class Kombinasi : protected FindValue{
    private:
        //0-1 player, sisanya table
        vector<DeckCard> arr;

        /* Array of Pairs. Mungkin Kosong mungkin terisi */
        vector<DeckCard> arrPair;
        vector<DeckCard> arrTwoPair;
        vector<DeckCard> arrThreeOfKind;
        vector<DeckCard> arrStraight;
        vector<DeckCard> arrFlush;
        vector<DeckCard> arrFullHouse;
        vector<DeckCard> arrFourAKind;
        vector<DeckCard> arrStraightFlush;

        const double MAX_HIGH_CARD = 1.31;
        const double MAX_PAIR = MAX_HIGH_CARD + 1.31 + 1.301;
        const double MAX_TWO_PAIR = MAX_PAIR + 1.3001 + 1.3;
        const double MAX_THREE_KIND = MAX_TWO_PAIR + 1.31 + 1.301 + 1.3001;
        const double MAX_STRAIGHT = MAX_THREE_KIND + 1.31 + 1.21 + 1.11 + 1.01 + 0.91;
        const double MAX_FLUSH = MAX_STRAIGHT + 1.31 + 1.21 + 1.11 + 1.01 + 0.91;
        const double MAX_FULL_HOUSE = MAX_FLUSH + 1.31 + 1.301 + 1.3001;
        const double MAX_FOUR_KIND = MAX_FULL_HOUSE + 1.31 + 1.301 + 1.3001 + 1.30;
        const double MAX_STRAIGHT_FLUSH = MAX_FULL_HOUSE + 1.31 + 1.21 + 1.11 + 1.01 + 0.91;

    public:
        /* Default Constructor */
        Kombinasi();
        Kombinasi(DeckCardCollection playerCards, DeckCardCollection tableCards);
        ~Kombinasi();
        /* Setter */
        /* Set Kartu dari playerCards dan tableCards*/
        void setCards(DeckCardCollection playerCards, DeckCardCollection tableCards);

        /* Nentuin value kartu untuk kombinasi */
        double value();
        string getCombinationName();

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
        // double HighCard(); Digabung sama value()
        bool isPair();
        bool isTwoPair();
        bool isThreeOfKind();
        bool isStraight();
        bool isFlush();
        bool isFullHouse();
        bool isFourAKind();
        bool isStraightFlush();
};
template<class T>
T maxVector(vector<T>& v)
{
    if (v.size()>0)
    {
        T temp = v[0];
        for (int i = 0 ; i < v.size() ; i++)
        {
            if (v[i]>temp)
            {
                temp = v[i];
            }
        }
        return temp;
    }
}


#endif
