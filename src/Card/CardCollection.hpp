#ifndef CARD_COLLECTION_HPP
#define CARD_COLLECTION_HPP
#include <iostream>
#include <fstream>

#include "DeckCard.hpp"
#include "AbilityCard.hpp"
#include "Abilities.hpp"
#include "UnoCard.hpp"
#include "UnoPlayCards.hpp"
#include "UnoActionCard.hpp"

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
        // T takeCard();
        void setCard(T&);
        void operator+(T&);
        void operator-(T&);
        void Del(T&);
        void displayDeckCard();
        // void displayCapsa();
        void clear();
        void addCard(T&);
        T& getRightCard();
        T& getLeftCard();
        void setLeftCard(T&);
        void setRightCard(T&);
        vector<T> getBuffer();
        
};

template class CardCollection<DeckCard>;
template class CardCollection<AbilityCard*>;
template class CardCollection<UnoCard*>;
#endif