/* Filename: Player.cpp 
    Implementasi Kelas Player */
#include "Player.hpp"

int Player::countOfPlayers = 0;

Player::Player()
{
    this->countofTableCard= 0;
    this->countofPlayerCards = 0;
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

Player& Player::operator+(DeckCard& cardInput){
    playerCard[countofPlayerCards] = cardInput;
    countofPlayerCards++;
    return *this;
}

void Player::addTableCard(DeckCard& tempCard)
{
    tableCard[countofTableCard] = tempCard;
    countofTableCard++;
}
void Player::viewAllCard()
{
    cout<<"List of Player Cards : "<<endl;
    for (int i = 0 ; i<countofPlayerCards ; i++)
    {
        playerCard[i].printInfo();
    }
    cout<<"List of Table Cards : "<< endl;
    for(int i = 0 ; i<countofTableCard ;  i++)
    {
        cout<<tableCard[i].getNum()<<tableCard[i].getType()<<endl;
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

int Player::value(DeckCard c){
    return ((c.getNum()/10) + 0.03 * (c.getType()-1));
}