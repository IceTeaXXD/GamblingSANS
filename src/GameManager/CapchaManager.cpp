#include "CapchaManager.hpp"

CapchaManager::CapchaManager()
{
    this->players = ArrOfPlayer(4);
}

CapchaManager::~CapchaManager()
{
}

void CapchaManager::startGame()
{
    this->players;
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