/* Filename: Player.cpp 
    Implementasi Kelas Player */
#include "Player.hpp"

int Player::countOfPlayers = 0;

Player::Player()
{
    countOfPlayers++;
    this->id = countOfPlayers;
}

CandyGamePlayer::CandyGamePlayer() : Player()
{
    this->countofPlayerCards = 0;
    this->hasAbility = false;
}

Player::Player(string nom):name(nom), point(0)
{ 
    countOfPlayers++; 
    this->id = countOfPlayers;
}

CandyGamePlayer::CandyGamePlayer(string nom): countofPlayerCards(0), Player(nom)
{
    this->hasAbility = false;
}

CandyGamePlayer::~CandyGamePlayer(){}

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

void CandyGamePlayer::operator+(DeckCard& cardInput){
    CardCollection<DeckCard>::operator+(cardInput);
    this->countofPlayerCards++;
}

void CandyGamePlayer::operator+(AbilityCard& ac){
    this -> abilityCards = &ac;
}

void Player::viewAllCard()
{
    cout << "List of Cards" << endl;
}

void CandyGamePlayer::viewAllCard(){
    cout<<"List of Player Cards : "<<endl;
    for (int i = 0 ; i<countofPlayerCards ; i++)
    {
        CardCollection<DeckCard>::getCard(i).printInfo();
        cout << "\n";
    }

    cout << endl;
    
    cout << "Ability Cards: " << endl;
    if(hasAbility){
        this->abilityCards->printInfo();
        cout << "Status: ";
        if(this->abilityCards->isAvailable()){
            cout << "Available" << endl;
        }else{
            cout << "Not Available" << endl;
        }
    }else{
        cout << "Belum ada ability card" << endl;
    }
}
// void Player::viewAllCardCapsa()
// {
//     cout<<"List of Player Cards : "<<endl;
//     cout<<"[";
//     for (int i = 0 ; i<countofPlayerCards-1 ; i++)
//     {
//         this->playerCard.getCard(i).printType();
//         cout<<",";
//     }
//     playerCard.getCard(countofPlayerCards-1).printType();
//     cout<<"]";
//     cout << endl;
// }
vector<DeckCard> CandyGamePlayer::getCard()
{
    return CardCollection<DeckCard>::buffer;
}

void CandyGamePlayer::setLeftCard(DeckCard& card){
    CardCollection<DeckCard>::setLeftCard(card);
}

void CandyGamePlayer::setRightCard(DeckCard& card){
    CardCollection<DeckCard>::setRightCard(card);
}

AbilityCard& CandyGamePlayer::getAbilityCard(){
    return *abilityCards;
}

bool CandyGamePlayer::operator<(CandyGamePlayer& other){
    return (this->point < other.point);
}

bool CandyGamePlayer::operator>(CandyGamePlayer& other){
    return (this->point > other.point);
}

bool CandyGamePlayer::operator==(CandyGamePlayer& other){
    return (this->point == other.point);
}

void CandyGamePlayer::clearCards(){
    CardCollection<DeckCard>::clear();
    this->countofPlayerCards = 0;
}

void CandyGamePlayer::setHasAbility(bool s){
    this->hasAbility = s;
}

bool CandyGamePlayer::getHasAbility(){ return this->hasAbility; }