#ifndef CARD_COLLECTION_HPP
#define CARD_COLLECTION_HPP
#include <iostream>
#include <fstream>

#include "DeckCard.hpp"
// #include "AbilityCard.hpp"

template <class T>
class CardCollection{
    protected:
        vector<T> buffer;
    public:
        CardCollection();
        ~CardCollection();

        /* Membuat sebuah deck untuk kartu X*/
        void MakeDeck();
        void MakeDeck(string filename);

        T getCard(int);
        T takeCard();
        void setCard(T&);
        void operator+(T&);
        void displayDeckCard();
        void clear();
        void addCard(T&);
        
};

template class CardCollection<DeckCard>;
// template class CardCollection<AbilityCard*>;

#endif