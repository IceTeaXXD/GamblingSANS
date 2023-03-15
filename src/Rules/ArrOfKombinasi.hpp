#ifndef ARR_OF_KOMBINASI_HPP
#define ARR_OF_KOMBINASI_HPP
#include "Kombinasi.hpp"
#include "KombinasiCapsa.hpp"
#include "../Card/CardCollection.hpp"

class ArrOfKombinasi
{
    private:
        vector<KombinasiCapsa> arrLima;
        vector<KombinasiCapsa> arrEmpat;
        vector<KombinasiCapsa> arrTiga;
        vector<KombinasiCapsa> arrDua;
        vector<KombinasiCapsa> arrSatu;
        vector<KombinasiCapsa*> dropComb;
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
        vector<KombinasiCapsa> getCombinationList(int);
        void displaySpecificCombination(string);
        KombinasiCapsa* DropCombination(int);
        int dropCombSize();
        ArrOfKombinasi& operator=(ArrOfKombinasi);
};
#endif