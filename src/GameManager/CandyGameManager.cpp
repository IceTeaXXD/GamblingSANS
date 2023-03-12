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

        cout << players.getPlayer(0).getName() << " melakukan SWAPCARD." << endl;
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
        for (int i = 1; i < 7; i++){
            cout << i << ". " << players.getPlayer(i).getName() << endl;
        }
        int pilihan1;
        cout << ">> ";
        cin >> pilihan1;
        cout << "Silahkan pilih pemain lain yang kartunya ingin anda tukar:" << endl;
        for (int i = 1; i < 7; i++){
            if (i != pilihan1){
                cout << i << ". " << players.getPlayer(i).getName() << endl;
            }
        }
        int pilihan2;
        cout << ">> ";
        cin >> pilihan2;
        cout << "Silakan pilih kartu kanan/kiri " << players.getPlayer(pilihan1).getName() << ":" << endl;
        cout << "1. Kanan" << endl;
        cout << "2. Kiri" << endl;
        int pilihan3;
        cout << ">> ";
        cin >> pilihan3;
        cout << "Silakan pilih kartu kanan/kiri " << players.getPlayer(pilihan2).getName() << ":" << endl;
        cout << "1. Kanan" << endl;
        cout << "2. Kiri" << endl;
        int pilihan4;
        cout << ">> ";
        cin >> pilihan4;

        // move to a temp card first
        DeckCard p1Left = players.getPlayer(pilihan1).getCard().getLeftCard();
        DeckCard p1Right = players.getPlayer(pilihan1).getCard().getRightCard();
        DeckCard p2Left = players.getPlayer(pilihan2).getCard().getLeftCard();
        DeckCard p2Right = players.getPlayer(pilihan2).getCard().getRightCard();
        
        // swap the card and remove swappee card
        if (pilihan3 == 1){
            if (pilihan4 == 1){
                players.setPlayerRightCard(pilihan1, p2Right);
                players.setPlayerRightCard(pilihan2, p1Right);
            }
            else{
                players.setPlayerRightCard(pilihan1, p2Left);
                players.setPlayerLeftCard(pilihan2, p1Right);

            }
        }
        else{
            if (pilihan4 == 1){
                players.setPlayerLeftCard(pilihan1, p2Right);
                players.setPlayerRightCard(pilihan2, p1Left);
            }
            else{
                players.setPlayerLeftCard(pilihan1, p2Left);
                players.setPlayerLeftCard(pilihan2, p1Left);
            }
        }
        
        /* OUTPUT */
        cout << "Kartu berhasil ditukar" << endl;

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