/* Filename: Player.cpp 
    Implementasi Kelas Player */
#include "Player.hpp"

int Player::countOfPlayers = 0;

Player::Player()
{
    this->countofTableCard= 0;
    this->countofPlayerCards = 0;
    this->playerCard = new DeckCard[2];
    this->tableCard = new DeckCard[5];
}

Player::Player(string nom):name(nom), point(0), countofPlayerCards(0), countofTableCard(0)
{ 
    countOfPlayers++; 
    this->id = countOfPlayers;
    this->playerCard = new DeckCard[2];
    this->tableCard = new DeckCard[5];
}

Player::~Player()
{ 
    countOfPlayers--; 
    delete[] playerCard;
    delete[] tableCard;
}

string Player::getName(){
    return this->name;
}

int Player::getID(){
    return this->id;
}

int Player::getPoint(){
    return this->point;
}

void Player::setPoint(int p){
    this->point = p;
}

void Player::operator<<(Card& tempCard)
{
    playerCard[countofPlayerCards] = tempCard;
    countofPlayerCards++;
}
void Player::addTableCard(Card& tempCard)
{
    tableCard[countofTableCard] = tempCard;
    countofTableCard++;
}
void Player::viewAllCard()
{
    cout<<"List of Player Cards : "<<endl;
    for (int i = 0 ; i<countofPlayerCards ; i++)
    {
        // cout<<playerCard[i].getNum()<<playerCard[i].getType()<<endl;
        playerCard[i].printInfo();
    }
    cout<<"List of Table Cards : "<< endl;
    for(int i = 0 ; i<countofTableCard ;  i++)
    {
        cout<<tableCard[i].getNum()<<tableCard[i].getType()<<endl;
    } 
}
