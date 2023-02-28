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
        DeckCard* tableCards;
        static int numOfTableCards;
        int point;

        /* Game Round */
        static int round;

        GameManager();
        ~GameManager();
        void setGiliran(int);
        int getGiliran();
        void startGame();
        void displayPlayer();
        void initDistribute(int);
        DeckCard* getCard();
};

#endif