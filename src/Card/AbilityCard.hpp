#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP

#include <iostream>
using namespace std;

class AbilityCard{
    protected:
        bool availability;
        string type;
    public:
        AbilityCard();
        AbilityCard(bool);
        bool isAvailable();
        void setNotAvailable();
        string getType();
        virtual void printInfo() = 0;
};

#endif