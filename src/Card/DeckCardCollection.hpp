#ifndef DECKCARDCOLLECTION_HPP
#define DECKCARDCOLLECTION_HPP
#include <iostream>
#include "DeckCard.hpp"

class DeckCardCollection{
    private:
        vector<DeckCard> buffer;
    public:
        /*  Default CTOR: Kreator Kosong    */
        DeckCardCollection();
        ~DeckCardCollection();

        /*  Membuat deck kartu sebanyak 52 kartu    */
        void MakeDeck();
        
        DeckCard getCard(int);
        DeckCard takeCard();
        void setCard(DeckCard&);
        void operator+(DeckCard&);
};
#endif