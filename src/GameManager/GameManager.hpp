#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include "../Player/Player.hpp"
#include "../Card/Card.hpp"

#include <iostream>
using namespace std;

class GameManager{
    private:
        /* Array of Players */
        Player* players;
        int giliran;
    public:
        /* Card Deck */
        Card* tableCards;
        static int numOfTableCards;

        /* Game Round */
        static int round;

        GameManager();
        ~GameManager();
        void setGiliran(int);
        int getGiliran();

};

#endif