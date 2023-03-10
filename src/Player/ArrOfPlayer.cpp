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
    // this->printDeque();
    arr.push_back(arr.at(0));
    arr.pop_front();

}

void ArrOfPlayer::reverseTurn(int round){
    reverse(arr.begin(), arr.end());
    for (int i = 0 ; i < round-1 ; i++){
        nextTurn();
    }
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

void ArrOfPlayer::addAbilityCard(int idx, AbilityCard& card){
    this->arr[idx] + card;
}


void ArrOfPlayer::clearCard(int i){
    arr[i].clearCards();
}

void ArrOfPlayer::printDeque(){
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i].getName() << endl;
    }
}
