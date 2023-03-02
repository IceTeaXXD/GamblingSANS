/* Filename: Player.cpp 
    Implementasi Kelas Player */
#include "Player.hpp"

int Player::countOfPlayers = 0;

Player::Player()
{
    this->countofTableCard= 0;
    this->countofPlayerCards = 0;
    countOfPlayers++;
    this->id = countOfPlayers;
}

Player::Player(string nom):name(nom), point(0), countofPlayerCards(0), countofTableCard(0)
{ 
    countOfPlayers++; 
    this->id = countOfPlayers;
}

Player::~Player()
{ 
    countOfPlayers--; 
}

string Player::getName(){
    return this->name;
}

void Player::setName(string name){
    this->name = name;
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

void Player::operator+(DeckCard& cardInput){
    this->playerCard + cardInput;
    this->countofPlayerCards++;
}


void Player::viewAllCard()
{
    cout<<"List of Player Cards : "<<endl;
    for (int i = 0 ; i<countofPlayerCards ; i++)
    {
        this->playerCard.getCard(i)->printInfo();
    }
}

bool Player::operator<(Player& other){
    return (this->point < other.point);
}

bool Player::operator>(Player& other){
    return (this->point > other.point);
}

bool Player::operator==(Player& other){
    return (this->point == other.point);
}

double Player::value()
{
    return (playerCard.getCard(0)->getNum()/10+playerCard.getCard(1)->getNum()/10 + (playerCard.getCard(0)->getType()-1) * 0.3 + (playerCard.getCard(1)->getType()-1) * 0.3);
}