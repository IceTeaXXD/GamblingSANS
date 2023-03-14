#include "ArrOfPlayer.hpp"

template <class T>
ArrOfPlayer<T>::ArrOfPlayer(){
    string name;
    for (int i = 0; i < 7; i++){
        cout << "Masukan nama player " << i+1 << " : ";
        cin >> name;
        T p(name);
        this->arr.push_back(p);
    }
    
}

template <class T>
ArrOfPlayer<T>:: ArrOfPlayer(int n){
    string name;
    for (int i = 0; i < n; i++){
        cout << "Masukan nama player " << i+1 << " : ";
        cin >> name;
        T p(name);
        this->arr.push_back(p);
    }
}

template <class T>
ArrOfPlayer<T>::~ArrOfPlayer(){
    this->arr.clear();
}

template <>
void ArrOfPlayer<CandyGamePlayer>::nextTurn(){
    // this->printDeque();
    // cout << endl;
    arr.push_back(arr.at(0));
    arr.pop_front();
    // this->printDeque();
}

template <>
void ArrOfPlayer<CapsaGamePlayer>::nextTurn(){
    // this->printDeque();
    // cout << endl;
    arr.push_back(arr.at(0));
    arr.pop_front();
    // this->printDeque();
}
template <>
void ArrOfPlayer<CandyGamePlayer>::reverseTurn(int turn){
    reverse(arr.begin(), arr.end());
    if (turn == 0){
        arr.push_front(arr.back());
        arr.pop_back();
    }else{
        for (int i = 0 ; i < turn-1 ; i++){
            nextTurn();
        }
    }
}

template <class T   >
T ArrOfPlayer<T>::getPlayer(int idx){
    return this->arr[idx];
}

template <class T>
T* ArrOfPlayer<T>::getPlayerAddress(int idx)
{
    return &this->arr[idx];
}

template <class T>
void ArrOfPlayer<T>::changePlayerName(int idx, string name){
    this->arr[idx].setName(name);
}

template <>
void ArrOfPlayer<CandyGamePlayer>::setPlayerPoint(int idx, long long point){
    this->arr[idx].setPoint(point);
}

template <>
void ArrOfPlayer<CandyGamePlayer>::addPlayerCard(int idx, DeckCard& card){
    this->arr[idx] + card;
}
template <>
void ArrOfPlayer<CapsaGamePlayer>::addPlayerCard(int idx, DeckCard& card)
{
    this->arr[idx] + card;
}

template<>
vector<DeckCard>& ArrOfPlayer<CapsaGamePlayer>::getAllPlayerCard(int idx)
{
    return arr[idx].getCard();
}

template <>
void ArrOfPlayer<CandyGamePlayer>::addAbilityCard(int idx, AbilityCard& card){
    this->arr[idx] + card;
    this->arr[idx].setHasAbility(true);
}
template <>
void ArrOfPlayer<CapsaGamePlayer>::addAbilityCard(int idx, AbilityCard& card){}

template <>
void ArrOfPlayer<CandyGamePlayer>::clearCard(int i){
    arr[i].clearCards();
}

template <class T>
void ArrOfPlayer<T>::printDeque(){
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i].getName() << endl;
    }
}

template <>
void ArrOfPlayer<CandyGamePlayer>::setPlayerLeftCard(int idx, DeckCard& card){
    this->arr[idx].setLeftCard(card);
}
template <>
void ArrOfPlayer<CapsaGamePlayer>::setPlayerLeftCard(int idx, DeckCard& card){
}
template <>
void ArrOfPlayer<CandyGamePlayer>::setPlayerRightCard(int idx, DeckCard& card){
    this->arr[idx].setRightCard(card);
}
template <>
void ArrOfPlayer<CapsaGamePlayer>::setPlayerRightCard(int idx, DeckCard& card){}