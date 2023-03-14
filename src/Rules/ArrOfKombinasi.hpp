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
    public:
        ArrOfKombinasi();
        ArrOfKombinasi(vector<DeckCard>);
        ~ArrOfKombinasi();
        // Kombinasi& getKombinasi(int);
        void addKombinasi(Kombinasi& k);
        void displayKombinasi();
};
#endif