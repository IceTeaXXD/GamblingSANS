#include "CapchaManager.hpp"

CapchaManager::CapchaManager()
{
    // this->players = ArrOfPlayer(4);
    players = new ArrOfPlayer<CapsaGamePlayer>(4);
}

CapchaManager::~CapchaManager()
{
    cout<<"Thank You For Playing The Game!"<<endl;
}
void CapchaManager::setGiliran(int giliran)
{
    for (int i = 0; i < 4; i++)
    {
        srand(time(NULL));
        int random = rand() % 4;
        this->giliran = random;
    }
}
ArrOfPlayer<CapsaGamePlayer>& CapchaManager::getPlayers()
{
    return *players;
}

CardCollection<DeckCard>* CapchaManager::getCards()
{
    return &this->Cards;
}

bool CapchaManager::parseCommand(string aksi){
    
}