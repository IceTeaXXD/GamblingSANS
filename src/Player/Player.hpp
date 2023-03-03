#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "../Card/DeckCard.hpp"
#include "../Card/DeckCardCollection.hpp"
// #include "../Card/AbilityCard.hpp
#include "../Rules/FindValue.hpp"

using namespace std;

/* Kelas untuk Player */
class Player{
    private:
        /* Nama dari Pemain */
        int id;
        string name;
        int point;

        /* Player Cards */
        DeckCardCollection playerCard;
        
        /* Ability Cards */
        // AbilityCard* abilityCards;

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
        int getPoint();
        void setPoint(int);
        static int countOfPlayers;
        int countofPlayerCards;
        int countofTableCard;
        void operator+(DeckCard&);
        void addTableCard(DeckCard&);
        void viewAllCard();
        DeckCardCollection getCard();
        bool operator<(Player&);
        bool operator>(Player&);
        bool operator==(Player&);

        /* Value yang digunakan untuk mencari nilai high card
            dari kartu yang dimiliki seorang player */
};

#endif