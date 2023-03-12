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
    this->hasAbility = false;
}

Player::Player(string nom):name(nom), point(0), countofPlayerCards(0), countofTableCard(0)
{ 
    countOfPlayers++; 
    this->id = countOfPlayers;
    this->hasAbility = false;
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

long long Player::getPoint(){
    return this->point;
}

void Player::setPoint(long long p){
    this->point = p;
}

void Player::operator+(DeckCard cardInput){
    this->playerCard + cardInput;
    this->countofPlayerCards++;
}

void Player::operator+(AbilityCard& ac){
    this -> abilityCards = &ac;
}

void Player::viewAllCard()
{
    cout<<"List of Player Cards : "<<endl;
    for (int i = 0 ; i<countofPlayerCards ; i++)
    {
        this->playerCard.getCard(i).printInfo();
    }
}
void Player::viewAllCardCapsa()
{
    cout<<"List of Player Cards : "<<endl;
    cout<<"[";
    for (int i = 0 ; i<countofPlayerCards ; i++)
    {
        this->playerCard.getCard(i).printType();
    }
    cout<<"]"<<endl;
}
CardCollection<DeckCard> Player::getCard()
{
    return this->playerCard;
}

AbilityCard& Player::getAbilityCard(){
    return *abilityCards;
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

void Player::clearCards(){
    this->playerCard.clear();
    this->countofPlayerCards = 0;
}

bool Player::isabilityCardEmpty(){
    return (this->abilityCards == NULL);
}

void Player::setHasAbility(bool s){
    this->hasAbility = s;
}

bool Player::getHasAbility(){ return this->hasAbility; }