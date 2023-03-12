#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "../Card/DeckCard.hpp"
// #include "../Card/DeckCardCollection.hpp"
#include "../Card/CardCollection.hpp"
// #include "../Card/AbilityCard.hpp
#include "../Rules/FindValue.hpp"

using namespace std;

/* Kelas untuk Player */
class Player{
    private:
        /* Nama dari Pemain */
        int id;
        string name;
        long long point;
        bool hasAbility;

        /* Player Cards */
        CardCollection<DeckCard> playerCard;
        
        /* Ability Cards */
        AbilityCard* abilityCards;

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
        static int countOfPlayers;
        int countofPlayerCards;
        int countofTableCard;
        void operator+(DeckCard);
        void operator+(AbilityCard&);
        void addTableCard(DeckCard&);
        void viewAllCard();
        void viewAllCardCapsa();
        CardCollection<DeckCard> getCard();
        AbilityCard& getAbilityCard();
        bool operator<(Player&);
        bool operator>(Player&);
        bool operator==(Player&);
        void clearCards();
        bool isabilityCardEmpty();
        void setHasAbility(bool s);
        bool getHasAbility();
        /* Value yang digunakan untuk mencari nilai high card
            dari kartu yang dimiliki seorang player */
};

#endif