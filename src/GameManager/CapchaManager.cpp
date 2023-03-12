#include "CapchaManager.hpp"

CapchaManager::CapchaManager()
{
    // this->players = ArrOfPlayer(4);
    players = new ArrOfPlayer(4);
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
