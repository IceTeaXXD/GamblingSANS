#include "CandyGameManager.hpp"

CandyGameManager::CandyGameManager()
{
    abilityCardList.MakeDeck();
}
CandyGameManager::CandyGameManager(string f) : GameManager(f)
{
    abilityCardList.MakeDeck();
}

CardCollection<AbilityCard*>& CandyGameManager::getAbilityCardList()
{
    return abilityCardList;
}
CardCollection<DeckCard>& CandyGameManager::getPlayCards()
{
    return playCards;
}
template<>
void CandyGameManager::manipulate<REROLL&>(REROLL& C){
    if (C.isAvailable())
    {
        C.setNotAvailable();

        /* Kosongkan Kartu terlebih dahulu */
        players.getPlayer(0).clearCards();

        /* Tambahin Kartu Baru */
        players.getPlayer(0) + tableCards.takeCard();

        /* OUTPUT */
        cout<<"RE-ROLLED"<<endl;
        players.getPlayer(0).viewAllCard();
    }
    else
    {
        cout << "Anda tidak memiliki kartu ini!" << endl;
    }
}

template <>
void CandyGameManager::manipulate<Quadruple&>(Quadruple& C){
    if (C.isAvailable()){
        C.setNotAvailable();

        /* Set point jadi 4 kali */
        setPoint(this->point*4);

        /* OUTPUT */
        cout << "Point berubah menjadi " << this->point << endl;
    }
    else{
        cout << "Anda tidak memiliki kartu ini" << endl;
    }
}

template<>
void CandyGameManager::manipulate<Quarter&>(Quarter& C){
    if (C.isAvailable()){
        C.setNotAvailable();

        /* Set point jadi 1/4 */
        setPoint(this->point/4);

        /* OUTPUT */
        cout << "Point berubah menjadi " << this->point << endl;
    }
    else{
        cout << "Anda tidak memiliki kartu ini" << endl;
    }
}

template<>
void CandyGameManager::manipulate<ReverseDirection&>(ReverseDirection& C){
    if (C.isAvailable()){
        C.setNotAvailable();

        /* Reverse direction */
        players.reverseTurn(this->round);

        /* OUTPUT */
        cout << "Direction berubah" << endl;
    }
    else{
        cout << "Anda tidak memiliki kartu ini" << endl;
    }
}

template<>
void CandyGameManager::manipulate<SwapCard&>(SwapCard& C){
    if (C.isAvailable()){
        C.setNotAvailable();

        /* Swap Card */
        // players.swapCard();

        /* OUTPUT */
        cout << "Kartu ditukar" << endl;
    }
    else{
        cout << "Anda tidak memiliki kartu ini" << endl;
    }
}

template<>
void CandyGameManager::manipulate<Switch&>(Switch& C){
    if (C.isAvailable()){
        C.setNotAvailable();

        /* Switch */
        // players.switch();

        /* OUTPUT */
        cout << "Switch" << endl;
    }
    else{
        cout << "Anda tidak memiliki kartu ini" << endl;
    }
}

template<>
void CandyGameManager::manipulate<Abilityless&>(Abilityless& C){
    if (C.isAvailable()){
        C.setNotAvailable();

        /* OUTPUT */
        cout << "Kartu tanpa ability" << endl;
    }
    else{
        cout << "Anda tidak memiliki kartu ini" << endl;
    }
}

template<>
void CandyGameManager::manipulate<AbilityCard&>(AbilityCard& C){
    if (C.getType() == "quadruple"){
        manipulate<Quadruple&>(dynamic_cast<Quadruple&>(C));
    }
    else if (C.getType() == "reverse"){
        manipulate<ReverseDirection&>(dynamic_cast<ReverseDirection&>(C));
    }
    else if (C.getType() == "reroll"){
        manipulate<REROLL&>(dynamic_cast<REROLL&>(C));
    }
    else if (C.getType() == "quarter"){
        manipulate<Quarter&>(dynamic_cast<Quarter&>(C));
    }
    else if (C.getType() == "swap"){
        manipulate<SwapCard&>(dynamic_cast<SwapCard&>(C));
    }
    else if (C.getType() == "switch"){
        manipulate<Switch&>(dynamic_cast<Switch&>(C));
    }
    else if (C.getType() == "abilityless"){
        manipulate<Abilityless&>(dynamic_cast<Abilityless&>(C));
    }else{
        cout << "Anda tidak memiliki kartu ini!" << endl;
    }
}