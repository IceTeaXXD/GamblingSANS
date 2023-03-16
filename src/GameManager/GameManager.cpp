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
    try{
        CardCollection<DeckCard>::MakeDeck(f);
    }catch (const std::invalid_argument){
        cout << "File tidak ada, membuat kartu secara otomatis" << endl;
        CardCollection<DeckCard>::MakeDeck();
    }
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

string GameManager::inputToLower(string str){
    for (int i = 0 ; i < str.length() ; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}