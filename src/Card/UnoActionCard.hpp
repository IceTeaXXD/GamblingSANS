#ifndef UNO_ACTION_CARD_HPP
#define UNO_ACTION_CARD_HPP

#include <iostream>
using namespace std;
#include "Warna.hpp"
#include "UnoCard.hpp"

class plus2 : public UnoCard {
    public:
        plus2();
        plus2(int);
        void printInfo();
};

class reversecard : public UnoCard {
    public:
        reversecard();
        reversecard(int);
        void printInfo();
};

class skip : public UnoCard {
    public:
        skip();
        skip(int);
        void printInfo();
};

class wildcard : public UnoCard{
    public:
        wildcard();
        void printInfo();
};

class wildcardplus4 : public UnoCard{
    public:
        wildcardplus4();
        void printInfo();
};

#endif