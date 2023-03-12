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
ArrOfPlayer :: ArrOfPlayer(int n){
    string name;
    for (int i = 0; i < n; i++){
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
    // cout << endl;
    arr.push_back(arr.at(0));
    arr.pop_front();
    // this->printDeque();
}

void ArrOfPlayer::reverseTurn(int turn){
    reverse(arr.begin(), arr.end());
    if (turn == 0){
        arr.push_front(arr.back());
        arr.pop_back();
    }else{
        for (int i = 0 ; i < turn-1 ; i++){
            cout << "NEXTT" << endl;
            nextTurn();
        }
    }
}

Player ArrOfPlayer::getPlayer(int idx){
    return this->arr[idx];
}

Player* ArrOfPlayer::getPlayerAddress(int idx)
{
    return &this->arr[idx];
}

void ArrOfPlayer::changePlayerName(int idx, string name){
    this->arr[idx].setName(name);
}

void ArrOfPlayer::setPlayerPoint(int idx, long long point){
    this->arr[idx].setPoint(point);
}

void ArrOfPlayer::addPlayerCard(int idx, DeckCard& card){
    this->arr[idx] + card;
}

void ArrOfPlayer::addAbilityCard(int idx, AbilityCard& card){
    this->arr[idx] + card;
    this->arr[idx].setHasAbility(true);
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

void ArrOfPlayer::setPlayerLeftCard(int idx, DeckCard& card){
    this->arr[idx].setLeftCard(card);
}

void ArrOfPlayer::setPlayerRightCard(int idx, DeckCard& card){
    this->arr[idx].setRightCard(card);
}