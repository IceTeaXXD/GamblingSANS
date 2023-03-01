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
    
}

ArrOfPlayer::~ArrOfPlayer(){
    this->arr.clear();
}

void ArrOfPlayer::nextTurn(){
    vector<Player> temp;
    for (int i = 1; i < 7; i++){
        temp.push_back(this->arr[i]);
    }
    temp.push_back(this->arr[0]);
    this->arr.clear();
    this->arr = temp;
}

void ArrOfPlayer::reverseTurn(){
    vector<Player> temp;
    for (int i = 0; i < 7; i++){
        temp.push_back(this->arr[i]);
    }
    this->arr.clear();
    this->arr = temp;
}

Player ArrOfPlayer::getPlayer(int idx){
    return this->arr[idx];
}

void ArrOfPlayer::changePlayerName(int idx, string name){
    this->arr[idx].setName(name);
}

void ArrOfPlayer::setPlayerPoint(int idx, int point){
    this->arr[idx].setPoint(point);
}

void ArrOfPlayer::addPlayerCard(int idx, DeckCard& card){
    this->arr[idx].addCard(card);
}

