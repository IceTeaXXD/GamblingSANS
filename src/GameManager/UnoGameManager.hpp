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
#include "../utils/printColor.hpp"
#include "../Exception/Exception.hpp"
using namespace std;


class UnoGameManager : public GameManager{
    private:
        ArrOfPlayer<UnoGamePlayer>* players;
        vector<string> winner;
        CardCollection<UnoCard*> playCard;
        CardCollection<UnoCard*> deckCards;
        printColor pc;
        string lastInput;

    public:
        UnoGameManager();
        ~UnoGameManager();
        void reset();
        ArrOfPlayer<UnoGamePlayer>& getPlayers();
        CardCollection<UnoCard*>& getPlayCard();
        CardCollection<UnoCard*>& getDeckCard();
        void distributeCard();
        template<class T>
        void manipulate(T);
        void putCard(UnoCard* card);
        bool parseCommand(string);
        bool isInputTrue(string) const;
        bool isGameOver();
        void displayWinner() const;
};

#endif