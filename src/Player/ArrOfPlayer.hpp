#ifndef ARROFPLAYER_HPP
#define ARROFPLAYER_HPP

#include <deque>
#include "Player.hpp"
#include "UnoPlayer.hpp"

template <class T>
class ArrOfPlayer {
    private :
        deque<T> arr;
        
    public :
        //ctor
        ArrOfPlayer();
        ArrOfPlayer(int);

        //dtor
        ~ArrOfPlayer();

        // Function
        void nextTurn();
        void reverseTurn(int);
        T getPlayer(int);
        void changePlayerName(int, string);
        void setPlayerPoint(int, long long);
        void addPlayerCard(int, DeckCard&);
        void addUnoPlayerCard(int, UnoCard&);
        vector<DeckCard>& getAllPlayerCard(int idx);
        void addAbilityCard(int, AbilityCard&);
        void clearCard(int i);
        void printDeque();
        void setPlayerLeftCard(int, DeckCard&);
        void setPlayerRightCard(int, DeckCard&);
        T* getPlayerAddress(int idx);
        int getSize();
};


template class ArrOfPlayer<CandyGamePlayer>;
template class ArrOfPlayer<UnoGamePlayer>;
template class ArrOfPlayer<CapsaGamePlayer>;

#endif