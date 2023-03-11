#include "CapchaManager.hpp"

CapchaManager::CapchaManager()
{
    this->players = ArrOfPlayer(4);
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
void CapchaManager::initDistribute(int id)
{
    for (int i = 0 ; i < 13 ; i++)
    {
        DeckCard card = Cards.CardCollection::getCard(0);
        
    }
}