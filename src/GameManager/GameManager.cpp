#include "GameManager.hpp"
#include <string>
int GameManager::numOfTableCards = 52;
GameManager::~GameManager(){ cout << "Thank You For Playing The Game!" << endl;}

void GameManager::setRound(int r){
    this->round = r;
}

int GameManager::getRound(){ return this->round; }

GameManager::GameManager():point(64)
{
    /* Inisialisasi DeckCard dengan memanggil MakeDeck()*/
    tableCards.MakeDeck();
    // abilityCardList.MakeDeck();
}

GameManager::GameManager(string f): point(64)
{
    tableCards.MakeDeck(f);
}

CardCollection<DeckCard> GameManager::getTableCards()
{
    return tableCards;
}
ArrOfPlayer GameManager::getPlayers()
{
    return players;
}
void GameManager::displayPlayer()
{
    for (int i = 0 ; i < 7 ; i++)
    {
        cout << "Player Number " << i+1 << players.getPlayer(i).getName() << endl;
    }
}

long long GameManager::getPoint()
{
    return this->point;
}

void GameManager::setPoint(long long p){this -> point = p;}

bool GameManager::isInputTrue(string input)
{
    return input == "next" || input == "double" || input == "half" || input == "quadruple" || input == "quarter" || input == "reroll" || input == "reverse" || input == "switch" || input == "swap" || input == "help" || input == "abilityless" || input == "2";
}

string GameManager::inputToLower(string str){
    for (int i = 0 ; i < str.length() ; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}
