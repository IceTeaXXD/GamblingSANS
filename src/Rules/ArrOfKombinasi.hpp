#ifndef ARR_OF_KOMBINASI_HPP
#define ARR_OF_KOMBINASI_HPP
#include "Kombinasi.hpp"
#include "../Card/CardCollection.hpp"
class ArrOfKombinasi
{
    private:
        vector<Kombinasi> arr;
    public:
        ArrOfKombinasi();
        ~ArrOfKombinasi();
        Kombinasi& getKombinasi(int);
        void addKombinasi(Kombinasi& k);
        void displayKombinasi();
};
#endif