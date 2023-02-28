#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "../Card/Card.hpp"
#include "../Card/AbilityCard.hpp"
using namespace std;

/* Kelas untuk Player */
class Player{
    private:
        /* Nama dari Pemain */
        int id;
        string name;
        int point;

        /* Player Cards */
        DeckCard* playerCard;
        DeckCard* tableCard;

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
        int getID();
        int getPoint();
        void setPoint(int);
        static int countOfPlayers;
        int countofPlayerCards;
        int countofTableCard;
        void operator<<(DeckCard&);
        void addTableCard(DeckCard&);
        void viewAllCard();
};

#endif