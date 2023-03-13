#include "GameManager.hpp"
#include <string>
int GameManager::numOfTableCards = 52;
GameManager::~GameManager(){ cout << "Thank You For Playing The Game!" << endl;}

void GameManager::setRound(int r){
    this->round = r;
}

int GameManager::getRound(){ return this->round; }

void GameManager::setTurn(int t){
    this->turn = t;
}

int GameManager::getTurn(){ return this->turn; }

GameManager::GameManager():point(64)
{
    /* Inisialisasi DeckCard dengan memanggil MakeDeck()*/
    CardCollection<DeckCard>::MakeDeck();
    // abilityCardList.MakeDeck();
}
GameManager::GameManager(int a):point(64)
{
    /* Inisialisasi DeckCard dengan memanggil MakeDeck()*/
    CardCollection<DeckCard>::MakeDeck();
    // abilityCardList.MakeDeck();
}

GameManager::GameManager(string f): point(64)
{
    CardCollection<DeckCard>::MakeDeck(f);
}

void GameManager::makeTableCards()
{
    CardCollection<DeckCard>::MakeDeck();
}

void GameManager::makeTableCards(string f)
{
    CardCollection<DeckCard>::MakeDeck(f);
}

vector<DeckCard>& GameManager::getTableCards()
{
    return buffer;
}

void GameManager::displayPlayer()
{
    cout << "PLAYERS" << endl;
}

long long GameManager::getPoint()
{
    return this->point;
}

void GameManager::setPoint(long long p){this -> point = p;}

bool GameManager::isInputTrue(string input)
{
    return input=="tablecards" || input == "viewcards" || input == "next" || input == "double" || input == "half" || input == "quadruple" || input == "quarter" || input == "reroll" || input == "reverse" || input == "switch" || input == "swap" || input == "help" || input == "abilityless" || input == "2";
}

string GameManager::inputToLower(string str){
    for (int i = 0 ; i < str.length() ; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}
