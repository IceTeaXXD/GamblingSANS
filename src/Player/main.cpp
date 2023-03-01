#include <iostream>
#include "Player.hpp"
#include "../Card/AbilityCard.hpp"
#include "../Card/DeckCard.hpp"
using namespace std;

int main()
{
    Player* player1 = new Player("NABIL");
    DeckCard* satukuning = new DeckCard(3,1);
    // cout<<"num : " << satukuning->getNum() << endl;
    // cout<<"type : " << satukuning->getType() << endl;
    //INI KNP GABISA DI ASSIGN DAH
    //MUNCULNYA ALAMAT MULU
    player1->addCard(*satukuning);
    player1->viewAllCard();
    return 0;
}