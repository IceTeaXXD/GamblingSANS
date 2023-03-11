#ifndef CAPCHA_MANAGER_HPP
#define CAPCHA_MANAGER_HPP

#include <iostream>
#include "../Player/Player.hpp"
#include "../Player/ArrOfPlayer.hpp"
#include "../Card/DeckCard.hpp"
#include "../Card/CardCollection.hpp"
#include "../Card/Abilities.hpp"
#include "../Card/AbilityCard.hpp"

using namespace std;

class CapchaManager{
    private:
        ArrOfPlayer players;
        int giliran;
        int point;
        CardCollection<DeckCard> Cards;

    public:
        CapchaManager();
        ~CapchaManager();

        void printInfo();
        void printInfoPlayer();
        void printInfoPlayerCard(int); //buat ngecek player punya kartu apa aja

        void initDistribute(int);
        void setGiliran(int);
        int getGiliran();
        void setPoint(int);
        

};

#endif