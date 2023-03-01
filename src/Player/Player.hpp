#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "../Card/DeckCard.hpp"
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
        void setName(string);
        int getID();
        int getPoint();
        void setPoint(int);
        static int countOfPlayers;
        int countofPlayerCards;
        int countofTableCard;
        Player& operator+(DeckCard&);

        void addTableCard(DeckCard&);
        void viewAllCard();
        bool operator<(Player&);
        bool operator>(Player&);
        bool operator==(Player&);
};

#endif