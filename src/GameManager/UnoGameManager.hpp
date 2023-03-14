#ifndef UNO_MANAGER_HPP
#define UNO_MANAGER_HPP

#include <iostream>
#include <stack>
#include <deque>
#include "GameManager.hpp"
#include "../Card/UnoCard.hpp"
#include "../Card/UnoActionCard.hpp"
#include "../Card/UnoPlayCards.hpp"
#include "../Player/Player.hpp"
#include "../Player/ArrOfPlayer.hpp"
#include "../Player/UnoPlayer.hpp"

using namespace std;


class UnoManager : public GameManager{
    private:
        ArrOfPlayer<UnoGamePlayer>* players;
        CardCollection<UnoCard*> playCards;
    public:
        UnoManager();
        UnoManager(string);
        ~UnoManager();
        void reset();
        
};

#endif