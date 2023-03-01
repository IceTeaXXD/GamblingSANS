#include <iostream>
#include "Player.hpp"
// #include "../Card/AbilityCard.hpp"
#include "../Card/DeckCard.hpp"
using namespace std;

int main()
{
    Player* player1 = new Player("NABIL");
    DeckCard* satukuning = new DeckCard(3,2);
    satukuning->printInfo();
    *player1+*satukuning;
    player1->viewAllCard();
    return 0;
}