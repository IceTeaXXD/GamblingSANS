#ifndef UNO_CARD_HPP
#define UNO_CARD_HPP

#include <iostream>
#include "../utils/printColor.hpp"
using namespace std;

class UnoCard{
    protected:
        printColor pc;
        string cardType;
    public:
        UnoCard();
        ~UnoCard();
        virtual void printInfo();
        virtual void setCardType(string);
        virtual string getCardType();
};

#endif