#ifndef UNOCARDCOLLECTION_HPP
#define UNOCARDCOLLECTION_HPP

#include <iostream>
#include <deque>
#include "UnoCard.hpp"
#include "UnoActionCard.hpp"

class UnoCardCollection{
    private:
        deque<UnoCard> buffer;
    public:
        UnoCardCollection();
        UnoCardCollection(int);
        void MakeDeck();
        void display();
        void useCard(int);
};

#endif