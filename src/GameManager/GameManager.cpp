#include "GameManager.hpp"
int GameManager::numOfTableCards = 52;
int GameManager::round = 1;
GameManager::~GameManager(){ cout << "Thank You For Playing The Game!" << endl;}


GameManager::GameManager()
{
    /* Inisialisasi DeckCard dengan memanggil MakeDeck()*/
    tableCards.MakeDeck();
    // abilityCardList = new AbilityCard[7];
    // abilityCardList[0] = new REROLL();
    // abilityCardList[1] = new Quadruple();
    // abilityCardList[2] = new Quarter();
    // abilityCardList[3] = new ReverseDirection();
    // abilityCardList[4] = new SwabCard();
    // abilityCardList[5] = new Switch();
    // abilityCardList[6] = new Abilityless();
}

// void GameManager::startGame()
// {
//     if (round == 1)
//     {
//         for (int i = 0 ; i < 7 ; i++)
//         {   int aksi;
//             initDistribute(giliran);
//             cout<<"Tentukan aksi anda: "<<endl;
//             cout<<"1. Next"<<endl;
//             cout<<"2. Double"<<endl;
//             cout<<"3. Half"<<endl;
//             cin>>aksi;
//             giliran++;
//         }
//         round++;
//         //kurang get ability card disini
//     }
//     else if (round>1 && round<6)
//     {
//         //distribute table card
//     }
// }

void GameManager::displayPlayer()
{
    for (int i = 0 ; i < 7 ; i++)
    {
        cout << "Player Number " << i+1 << players.getPlayer(i).getName() << endl;
    }
}

void GameManager::initDistribute(int idplayer)
{
    for (int i = 0 ; i < 7 ; i++)
    {
        DeckCard card = tableCards.DeckCardCollection::getCard(0);
        //ini harus dihapus sih yg awal
        players.getPlayer(idplayer)+card;
    }
}
// void GameManager::setGiliran(int g){this->giliran = 0;}

void GameManager::setPoint(int p){this -> point = p;}

// DeckCard* GameManager::getCard()
// {
//     int idx = rand()%numOfTableCards;
//     DeckCard* ret = &tableCards[idx];
//     for (int i = idx ; i < numOfTableCards ; i++)
//     {
//         tableCards[i] = tableCards[i+1];
//     }
//     delete[] &tableCards[numOfTableCards-1];
//     numOfTableCards--;
//     return ret;
// }

// AbilityCard* GameManager::getAbilityCard()
// {
//  //IMPELEMTASI DISINI 
//  //intinya ngerandom angka 0-length(abilityCardList) trs ambil sesuai yg di dapet + assign ke pemain
//  //Krtu ability yang udah diambil dihapus dari list
//  //sama kyk yang getCard()   
// } 
