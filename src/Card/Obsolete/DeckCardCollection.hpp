#ifndef DECKCARDCOLLECTION_HPP
#define DECKCARDCOLLECTION_HPP
#include <iostream>
#include <fstream>
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

        /* Make A Deck from A File */
        void MakeDeck(string filename);
        
        DeckCard getCard(int);
        DeckCard takeCard();
        void setCard(DeckCard&);
        void operator+(DeckCard&);
        void displayDeckCard();
        void clear();
        void addCard(DeckCard&);
};
#endif