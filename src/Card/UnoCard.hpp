#ifndef UNO_CARD_HPP
#define UNO_CARD_HPP

#include <iostream>
#include "../utils/printColor.hpp"
#include "Angka.hpp"
#include "Warna.hpp"
using namespace std;

class UnoCard : public Angka, public Warna{
    protected:
        printColor pc;
        string cardType;
    public:
        UnoCard();
        UnoCard(int,int);
        ~UnoCard();
        virtual void printInfo();
        virtual void setCardType(string);
        virtual string getCardType();
};

#endif