#ifndef ARR_OF_KOMBINASI_HPP
#define ARR_OF_KOMBINASI_HPP
#include "Kombinasi.hpp"
#include "KombinasiCapsa.hpp"
#include "../Card/CardCollection.hpp"

class ArrOfKombinasi
{
    private:
        vector<Kombinasi> arrLima;
        vector<Kombinasi> arrEmpat;
        vector<Kombinasi> arrTiga;
        vector<Kombinasi> arrDua;
        vector<Kombinasi> arrSatu;
        vector<Kombinasi*> dropComb;
        bool isStraightFlush;
        bool isFourAKind;
        bool isFullHouse;
        bool isFlush;
        bool isStraight;
        bool isThreeAKind;
        bool isTwoPair;
        bool isPair;
        bool isHighCard;
    public:
        ArrOfKombinasi();
        ArrOfKombinasi(vector<DeckCard>);
        ~ArrOfKombinasi();
        // Kombinasi& getKombinasi(int);
        void displayCombinationList();
        void addKombinasi(Kombinasi& k);
        void displayKombinasi();
        vector<Kombinasi> getCombinationList(int);
        void displaySpecificCombination(string);
        Kombinasi DropCombination(int);
        int dropCombSize();
};
#endif