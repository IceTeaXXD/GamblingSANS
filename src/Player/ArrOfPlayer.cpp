#include "ArrOfPlayer.hpp"

ArrOfPlayer::ArrOfPlayer(){
    string name;
    for (int i = 0; i < 7; i++){
        cout << "Masukan nama player " << i+1 << " : ";
        cin >> name;
        Player p(name);
        this->arr.push_back(p);
    }
    
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
    this->arr[idx] + card;
}

