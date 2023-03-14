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
        Kombinasi* lastPlayed;
        CardCollection<DeckCard> Cards;
        ArrOfPlayer<CapsaGamePlayer>* players;
        Kombinasi droppedCombination;
    public:
        CapchaManager();
        ~CapchaManager();
        CardCollection<DeckCard>* getCards();
        // void printInfo();
        // void printInfoPlayer();
        // void printInfoPlayerCard(int); //buat ngecek player punya kartu apa aja
        ArrOfPlayer<CapsaGamePlayer>& getPlayers();
        void setGiliran(int);
        Kombinasi getLastPlayed();
        void setLastPlayed(Kombinasi&);
        void clearLastPlayed();
        bool parseCommand(string);
        int firstPlayer();
        void setDroppedCombination(Kombinasi);
        Kombinasi& getDroppedCombination();
        // int getGiliran();
        // void setPoint(int);
        

};

#endif