#ifndef UNO_PLAY_CARDS_HPP
#define UNO_PLAY_CARDS_HPP

#include <iostream>
using namespace std;
#include "Angka.hpp"
#include "Warna.hpp"
#include "UnoCard.hpp"
#include "../utils/printColor.hpp"

class UnoPlayCards : public UnoCard{
    public:
        UnoPlayCards();
        UnoPlayCards(int, int);
        void printInfo();
};

#endif