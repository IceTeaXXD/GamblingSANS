#include "GameManager.hpp"
#include <string>
int GameManager::numOfTableCards = 52;
GameManager::~GameManager(){ cout << "Thank You For Playing The Game!" << endl;}

void GameManager::setRound(int r){
    this->round = r;
}

int GameManager::getRound(){ return this->round; }

GameManager::GameManager():point(64)
{
    /* Inisialisasi DeckCard dengan memanggil MakeDeck()*/
    tableCards.MakeDeck();
    abilityCardList.MakeDeck();
    // abilityCardList = new AbilityCard[7];
    // abilityCardList[0] = new REROLL();
    // abilityCardList[1] = new Quadruple();
    // abilityCardList[2] = new Quarter();
    // abilityCardList[3] = new ReverseDirection();
    // abilityCardList[4] = new SwabCard();
    // abilityCardList[5] = new Switch();
    // abilityCardList[6] = new Abilityless();
}

GameManager::GameManager(string f): point(64)
{
    tableCards.MakeDeck(f);
}

// void GameManager::startGame()
// {
//     if (round == 1)
//     {
//         for (int i = 0 ; i < 7 ; i++)
//         {   int aksi;
//             initDistribute(giliran);
//             cout<<"Tentukan aksi anda: "<<endl;
//             cout<<"1. Next"<<endl;
//             cout<<"2. Double"<<endl;
//             cout<<"3. Half"<<endl;
//             cin>>aksi;
//             giliran++;
//         }
//         round++;
//         //kurang get ability card disini
//     }
//     else if (round>1 && round<6)
//     {
//         //distribute table card
//     }
// }

void GameManager::displayPlayer()
{
    for (int i = 0 ; i < 7 ; i++)
    {
        cout << "Player Number " << i+1 << players.getPlayer(i).getName() << endl;
    }
}

void GameManager::initDistribute(int idplayer)
{
    for (int i = 0 ; i < 7 ; i++)
    {
        DeckCard card = tableCards.CardCollection::getCard(0);
        //ini harus dihapus sih yg awal
        players.getPlayer(idplayer)+card;
    }
}
// void GameManager::setGiliran(int g){this->giliran = 0;}

void GameManager::setPoint(long long p){this -> point = p;}

bool GameManager::isInputTrue(string input)
{
    return input == "next" || input == "double" || input == "half" || input == "quadruple" || input == "quarter" || input == "reroll" || input == "reverse" || input == "switch" || input == "swap" || input == "help" || input == "abilityless";
}

string GameManager::inputToLower(string str){
    for (int i = 0 ; i < str.length() ; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

// DeckCard* GameManager::getCard()
// {
//     int idx = rand()%numOfTableCards;
//     DeckCard* ret = &tableCards[idx];
//     for (int i = idx ; i < numOfTableCards ; i++)
//     {
//         tableCards[i] = tableCards[i+1];
//     }
//     delete[] &tableCards[numOfTableCards-1];
//     numOfTableCards--;
//     return ret;
// }

// AbilityCard* GameManager::getAbilityCard()
// {
//  //IMPELEMTASI DISINI 
//  //intinya ngerandom angka 0-length(abilityCardList) trs ambil sesuai yg di dapet + assign ke pemain
//  //Krtu ability yang udah diambil dihapus dari list
//  //sama kyk yang getCard()   
// } 

template<>
void GameManager::manipulate<REROLL&>(REROLL& C){
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
void GameManager::manipulate<Quadruple&>(Quadruple& C){
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
void GameManager::manipulate<Quarter&>(Quarter& C){
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
void GameManager::manipulate<ReverseDirection&>(ReverseDirection& C){
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
void GameManager::manipulate<SwapCard&>(SwapCard& C){
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
void GameManager::manipulate<Switch&>(Switch& C){
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
void GameManager::manipulate<Abilityless&>(Abilityless& C){
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
void GameManager::manipulate<AbilityCard&>(AbilityCard& C){
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