#include "ArrOfPlayer.hpp"

ArrOfPlayer::ArrOfPlayer(){
    Player p1;
    Player p2;
    Player p3;
    Player p4;
    Player p5;
    Player p6;
    Player p7;

    this->arr.push_back(p1);
    this->arr.push_back(p2);
    this->arr.push_back(p3);
    this->arr.push_back(p4);
    this->arr.push_back(p5);
    this->arr.push_back(p6);
    this->arr.push_back(p7);

    this->giliran = 0;
    
}

ArrOfPlayer::~ArrOfPlayer(){
    this->arr.clear();
}

int ArrOfPlayer::getGiliran(){
    return this->giliran;
}

void ArrOfPlayer::setGiliran(int giliran){
    this->giliran = giliran;
}

Player ArrOfPlayer::getPlayer(int idx){
    return this->arr[idx];
}

void ArrOfPlayer::changePlayerName(int idx, string name){
    this->arr[idx].setName(name);
}

void setPlayerPoint(int idx, int point){
    this->arr[idx].setPoint(point);
}

void addPlayerCard(int idx, DeckCard& card){
    this->arr[idx].addCard(card);
}

