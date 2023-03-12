#ifndef CARD_COLLECTION_HPP
#define CARD_COLLECTION_HPP
#include <iostream>
#include <fstream>

#include "DeckCard.hpp"
#include "AbilityCard.hpp"
#include "Abilities.hpp"

template <class T>
class CardCollection{
    protected:
        vector<T> buffer;
    public:
        CardCollection();
        ~CardCollection();

        /* Membuat sebuah deck untuk kartu T */
        void MakeDeck();
        void MakeDeck(string filename);

        T getCard(int);
        T takeCard();
        void setCard(T&);
        void operator+(T&);
        void displayDeckCard();
        void clear();
        void addCard(T&);
        T& getRightCard();
        T& getLeftCard();
        void setLeftCard(T&);
        void setRightCard(T&);
        
};

template class CardCollection<DeckCard>;
template class CardCollection<AbilityCard*>;

#endif