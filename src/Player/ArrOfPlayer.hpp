#ifndef ARROFPLAYER_HPP
#define ARROFPLAYER_HPP

#include <vector>
#include "Player.hpp"

class ArrOfPlayer {
    private :
        vector<Player> arr (7);
        int giliran;
    public :
        //ctor
        ArrOfPlayer();

        //dtor
        ~ArrOfPlayer();

        // Function
        int getGiliran();
        void setGiliran(int);
        Player getPlayer(int);
        void changePlayerName(int, string);
        void setPlayerPoint(int, int);
        void addPlayerCard(int, DeckCard&);
};

#endif