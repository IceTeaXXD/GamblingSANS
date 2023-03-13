#ifndef KOMBINASI_HPP
#define KOMBINASI_HPP
#include <iostream>
#include <algorithm>
#include <map>
#include "FindValue.hpp"
#include "../Card/DeckCard.hpp"
#include "../Card/CardCollection.hpp"

class Kombinasi : protected FindValue{
    private:
        //0-1 player, sisanya table
        vector<DeckCard> arr;
        vector<DeckCard> arrCombination;
        vector<DeckCard> arrTableCardCombination;

        const double MAX_HIGH_CARD = 1.31;
        const double MAX_PAIR = MAX_HIGH_CARD + 1.31 + 1.301;
        const double MAX_TWO_PAIR = MAX_PAIR + 1.31 + 1.3101 + 1.3001 + 1.3;
        const double MAX_THREE_KIND = MAX_TWO_PAIR + 1.31 + 1.301 + 1.3001;
        const double MAX_STRAIGHT = MAX_THREE_KIND + 1.31 + 1.21 + 1.11 + 1.01 + 0.91;
        const double MAX_FLUSH = MAX_STRAIGHT + 1.31 + 1.21 + 1.11 + 1.01 + 0.91;
        const double MAX_FULL_HOUSE = MAX_FLUSH + 1.31 + 1.301 + 1.3001 + 1.21 + 1.201;
        const double MAX_FOUR_KIND = MAX_FULL_HOUSE + 1.31 + 1.301 + 1.3001 + 1.30;
        const double MAX_STRAIGHT_FLUSH = MAX_FULL_HOUSE + 1.31 + 1.21 + 1.11 + 1.01 + 0.91;

    public:
        /* Default Constructor */
        Kombinasi();
        Kombinasi(CardCollection<DeckCard> playerCards, CardCollection<DeckCard> tableCards);
        ~Kombinasi();
        /* Setter */
        /* Set Kartu dari playerCards dan tableCards*/
        void setCards(CardCollection<DeckCard> playerCards, CardCollection<DeckCard> tableCards);

        /* Nentuin value kartu untuk kombinasi */
        double value();
        double tableValue();
        string getCombinationName();

        /* Bruteforcing untuk Kombinasi Kartu */
        int getCombination(DeckCard x, DeckCard tc);

        /* Operator overloading buat bandingin value */
        bool operator>(Kombinasi&);
        bool operator<(Kombinasi&);
        bool operator==(const Kombinasi&) const;

        Kombinasi& operator=(Kombinasi&);
        
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

        bool isTableCardPair();
        bool isTableCardTwoPair();
        bool isTableCardThreeOfKind();
        bool isTableCardStraight();
        bool isTableCardFlush();
        bool isTableCardFullHouse();
        bool isTableCardFourAKind();
        bool isTableCardStraightFlush();
};

template<class T>
T maxVector(vector<T>& v)
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

template <class T>
T maxArr(T* arr, int n){
    T maks = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i]>maks){
            maks = arr[i];
        }
    }
    return maks;
}

template <class T, size_t n>
T maxArr(T (&arr) [n]){
    if (n==0)
    {
        return "Array Kosong\n";
    }
    else
    {
        T maks = arr[0];
        for (int i = 1; i < n; i++){
            if (arr[i]>maks){
                maks = arr[i];
            }
        }
        return maks;
    }
}

template <class T, class N>
T maxKeyMap(map<T, N> Map){
    T maxKey = -1;
    for (const auto& pair : Map) {
        if (pair.first > maxKey) {
            maxKey = pair.first;
        }
    }
    return maxKey;
}

template <class T, class N>
T findKey(map<T, N> Map, N value){
    T key = -1;
    for (const auto& pair : Map) {
        if (pair.second == value) {
            key = pair.first;
            break;
        }
    }
    return key;
}
#endif
