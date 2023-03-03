#ifndef ARROFPLAYER_HPP
#define ARROFPLAYER_HPP

#include <vector>
#include "Player.hpp"

class ArrOfPlayer {
    private :
        vector<Player> arr;
    public :
        //ctor
        ArrOfPlayer();

        //dtor
        ~ArrOfPlayer();

        // Function
        void nextTurn();
        void reverseTurn();
        Player getPlayer(int);
        void changePlayerName(int, string);
        void setPlayerPoint(int, int);
        void addPlayerCard(int, DeckCard&);
        void clearCard(int i);
};

#endif