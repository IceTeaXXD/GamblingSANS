#ifndef ARROFPLAYER_HPP
#define ARROFPLAYER_HPP

#include <deque>
#include "Player.hpp"

class ArrOfPlayer {
    private :
        deque<Player> arr;
    public :
        //ctor
        ArrOfPlayer();
        ArrOfPlayer(int);

        //dtor
        ~ArrOfPlayer();

        // Function
        void nextTurn();
        void reverseTurn(int);
        Player getPlayer(int);
        void changePlayerName(int, string);
        void setPlayerPoint(int, long long);
        void addPlayerCard(int, DeckCard&);
        void addAbilityCard(int, AbilityCard&);
        void clearCard(int i);
        void printDeque();
        Player* getPlayerAddress(int idx);
};

#endif