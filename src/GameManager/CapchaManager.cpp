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
    return true;
}

int CapchaManager::firstPlayer(){
    vector<DeckCard> temp;
    vector<int> angka;
    for (int i = 0; i < 4; i++)
    {
        vector<DeckCard> buffer = players->getPlayer(i).getBuffer();
        temp.insert(temp.end(), buffer.begin(), buffer.end());
        buffer.clear();
    }
    for (int i = 0; i < temp.size(); i++)
    {
        angka.push_back(temp[i].getNum());
    }
    auto itr = find(angka.begin(), angka.end(), 3);
    while (temp[itr-angka.begin()].getType() != 4)
    {
       itr = find(itr+1, angka.end(), 3);
    }
    return (itr-angka.begin())/13;
}

Kombinasi CapchaManager::getLastPlayed(){
    return *lastPlayed;
}

void CapchaManager::setLastPlayed(Kombinasi& lastPlayed){
    this->lastPlayed = &lastPlayed;
}

void CapchaManager::clearLastPlayed(){
    delete this->lastPlayed;
}
void CapchaManager::setDroppedCombination(Kombinasi c)
{
    this->droppedCombination = &c;
}
Kombinasi& CapchaManager::getDroppedCombination()
{
    return *this->droppedCombination;
}