#ifndef UNO_ACTION_CARD_HPP
#define UNO_ACTION_CARD_HPP

#include <iostream>
using namespace std;
#include "Warna.hpp"
#include "UnoCard.hpp"

class plus2 : public UnoCard, public Warna{
    public:
        plus2();
        plus2(int);
        void printInfo();
};

class reversecard : public UnoCard, public Warna{
    public:
        reversecard();
        reversecard(int);
        void printInfo();
};

class skip : public UnoCard, public Warna{
    public:
        skip();
        skip(int);
        void printInfo();
};

class wildcard : public Warna, public UnoCard{
    public:
        wildcard();
        void printInfo();
};

class wildcardplus4 : public Warna, public UnoCard{
    public:
        wildcardplus4();
        void printInfo();
};

#endif