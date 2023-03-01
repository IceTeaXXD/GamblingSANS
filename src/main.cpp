#include <iostream>
// #include "Card/AbilityCard.hpp"
#include "Card/DeckCard.hpp"
#include "GameManager/GameManager.hpp"
#include "Player/Player.hpp"

int main()
{
    GameManager* game = new GameManager();
    int round = 1;
    while(true){
        if (round == 1){
            // for each player give 2 cards from table cards
            for (int i = 0 ; i < 7 ; i++){
                game->players.getPlayer(i)+game->tableCards.takeCard();
                game->players.getPlayer(i)+game->tableCards.takeCard();
            }

            for (int i = 0 ; i < 7 ; i++){
                cout<<"Tentukan aksi anda: "<<endl;
                cout<<"1. Next"<<endl;
                cout<<"2. Double"<<endl;
                cout<<"3. Half"<<endl;
                string aksi;
                cin>>aksi;
            }

            // Give 1 ability card to each player
            /* TODO */
        }

        else if(round >= 2 && round <= 6){
            game->playCards+game->tableCards.takeCard();

            for (int i = 0 ; i < 7 ; i++){
                cout<<"Tentukan aksi anda: "<<endl;
                cout<<"1. Next"<<endl;
                cout<<"2. Double"<<endl;
                cout<<"3. Half"<<endl;
                string aksi;
                cin>>aksi;
            }
        }

        round++;
    }
    return 0;
}