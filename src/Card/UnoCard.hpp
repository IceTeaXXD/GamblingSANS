#ifndef UNO_CARD_HPP
#define UNO_CARD_HPP

#include <iostream>
#include "Angka.hpp"
#include "Warna.hpp"
using namespace std;

class UnoCard : public Warna, public Angka{
    private:
    public:
        UnoCard();
        UnoCard(int, int);
        ~UnoCard();
        void printInfo();
};

#endif