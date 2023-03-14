#ifndef CAPCHA_MANAGER_HPP
#define CAPCHA_MANAGER_HPP

#include <iostream>
#include "../Player/Player.hpp"
#include "GameManager.hpp"
#include "../Player/ArrOfPlayer.hpp"
#include "../Card/DeckCard.hpp"
#include "../Card/CardCollection.hpp"
#include "../Card/Abilities.hpp"
#include "../Card/AbilityCard.hpp"

using namespace std;

class CapchaManager : public GameManager
{
    private:
        int giliran;
        int point;
        CardCollection<DeckCard> Cards;
        ArrOfPlayer<CapsaGamePlayer>* players;

    public:
        CapchaManager();
        ~CapchaManager();
        CardCollection<DeckCard>* getCards();
        // void printInfo();
        // void printInfoPlayer();
        // void printInfoPlayerCard(int); //buat ngecek player punya kartu apa aja
        ArrOfPlayer<CapsaGamePlayer>& getPlayers();
        void setGiliran(int);

        bool parseCommand(string);
        int firstPlayer();
        // int getGiliran();
        // void setPoint(int);
        

};

#endif