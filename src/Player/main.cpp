#include <iostream>
#include "Player.hpp"
#include "../Card/AbilityCard.hpp"
#include "../Card/Card.hpp"
using namespace std;

int main()
{
    Player* player1 = new Player("NABIL");
    DeckCard* satumerah = new DeckCard(3,1);
    cout<<satumerah->getNum();
    cout<<satumerah->getType();
    //INI KNP GABISA DI ASSIGN DAH
    //MUNCULNYA ALAMAT MULU 
    *player1<<*satumerah;
    cout<<player1->countofPlayerCards;
    player1->viewAllCard();
    return 0;
}