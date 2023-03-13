#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "../Card/DeckCard.hpp"
#include "../Card/CardCollection.hpp"
#include "../Rules/FindValue.hpp"

using namespace std;

/* Kelas untuk Player */
class Player{
    protected:
        /* Nama dari Pemain */
        int id;
        string name;
        long long point;

    public:
        /* ctor */
        Player();
        Player(string);
        /* dtor */
        ~Player();

        /* Functions */
        string getName();
        void setName(string);
        int getID();
        long long getPoint();
        void setPoint(long long);
        virtual void viewAllCard();
        static int countOfPlayers;
};

class CandyGamePlayer: public Player{
    private:
        /* Player Cards */
        CardCollection<DeckCard> playerCard;
        
        /* Ability Cards */
        AbilityCard* abilityCards;

        bool hasAbility;

    public:
        CandyGamePlayer();
        CandyGamePlayer(string);
        ~CandyGamePlayer();
        int countofPlayerCards;
        int countofTableCard;
        void operator+(DeckCard);
        void operator+(AbilityCard&);
        void viewAllCard();
        void setLeftCard(DeckCard&);
        void setRightCard(DeckCard&);
        CardCollection<DeckCard> getCard();
        AbilityCard& getAbilityCard();
        bool operator<(CandyGamePlayer&);
        bool operator>(CandyGamePlayer&);
        bool operator==(CandyGamePlayer&);
        void clearCards();
        void setHasAbility(bool s);
        bool getHasAbility();
};
#endif