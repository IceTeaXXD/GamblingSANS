#ifndef ARROFPLAYER_HPP
#define ARROFPLAYER_HPP

#include <bits/stdc++.h>
#include "Player.hpp"

class ArrOfPlayer {
    private :
        vector<Player> arr;
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
};

#endif