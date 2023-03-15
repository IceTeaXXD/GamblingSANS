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
vector<DeckCard>& CapsaGamePlayer::getCard()
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

CapsaGamePlayer::CapsaGamePlayer() : Player()
{
    countOfPlayerCards = 0;
}

CapsaGamePlayer::CapsaGamePlayer(string n) : Player(n)
{
    countOfPlayerCards = 0;
}

CapsaGamePlayer::~CapsaGamePlayer(){}

void CapsaGamePlayer::operator+(DeckCard& card)
{
    CardCollection<DeckCard>::operator+(card);
    countOfPlayerCards++;
}

void CapsaGamePlayer::operator-(KombinasiCapsa c)
{
    for(DeckCard card : c.getCombinationCard())
    {
        deleteCard(card);
        countOfPlayerCards--;
        // cout<<"Berhasil menghapus kartu"<<endl;
    }
    // arr.~ArrOfKombinasi();
    // this->arr = ArrOfKombinasi(getCard());
    //buat arrofkombinasi yang baru
}

void CapsaGamePlayer::viewAllCard()
{
    for (DeckCard card : buffer)
    {
        card.printInfoCapsa();

    }
}


void CapsaGamePlayer::deleteCard(DeckCard& el)
{
    vector<int> vecAngka;
    for (int i =0; i < buffer.size(); i++)
    {
        vecAngka.push_back(buffer[i].getNum());
    }
    auto it = find(vecAngka.begin(), vecAngka.end(), el.getNum());
    while (it != vecAngka.end() && buffer[it-vecAngka.begin()].getType() != el.getType())
    {
        it = find(it+1, vecAngka.end(), el.getNum());
    }
    if (it!=vecAngka.end())
    {
        buffer.erase(buffer.begin() + (it - vecAngka.begin())); // corrected line
        // cout<<"Berhasil menghapus elemen"<<endl;
    }
}

void CapsaGamePlayer::delete3Cards()
{
    vector<int> vecAngka;
    for (int i =0; i < buffer.size(); i++)
    {
        vecAngka.push_back(buffer[i].getNum());
    }
    auto it = find(vecAngka.begin(), vecAngka.end(), 3);
    while (it != vecAngka.end())
    {
        buffer.erase(buffer.begin() + (it - vecAngka.begin()));
        it = find(it+1, vecAngka.end(), 3);
    }
}

void CapsaGamePlayer::getAllGreaterCombination(Kombinasi& c)
{
    greaterComb.clear();
    // this->arr.~ArrOfKombinasi();
    this->arr = ArrOfKombinasi(this->getCard());
    this->canPlay = false;
    // int num = 0;
    // cout<<"HALOHALO"<<endl;
    // cout<<c.getCName()<<endl;
    // cout<<"HELOHELO"<<endl; 
    if (c.getCName() == "StraightFlush" || c.getCName() == "Flush" || c.getCName() == "FullHouse" || c.getCName() == "Straight")
    {
        for (int i = 0 ; i < arr.getCombinationList(5).size() ; i++)
        {
            if (arr.getCombinationList(5).at(i).getValue() > c.getValue())
            {
                // cout<<num+1<<". ";
                arr.getCombinationList(5).at(i).printKombinasi();
                greaterComb.push_back(&arr.getCombinationList(5).at(i));
                // cout<<"PRINT KOMBINASI"<<endl;
                // greaterComb.at(i)->printKombinasi();
                // cout<<endl;
                this->canPlay = true;
            }
            else
            {
                // cout<<"Sayang sekali, Anda tidak memiliki kartu Kombo 5 yang lebih tinggi"<<endl;
            }
        }
    }
    else if (c.getCName() == "FourAKind" || c.getCName() == "TwoPair")
    {
        for (int i = 0 ; i < arr.getCombinationList(4).size() ; i++)
        {
            if (arr.getCombinationList(4).at(i).getValue() > c.getValue())
            {
                // arr.getCombinationList(4)->at(i).printKombinasi();
                greaterComb.push_back(&arr.getCombinationList(4).at(i));
                // cout<<endl;
                this->canPlay = true;
            }
            else
            {
                // cout<<"Sayang sekali, Anda tidak memiliki kartu Kombo 4 yang lebih tinggi"<<endl;
            }
        }
    }
    else if (c.getCName() == "ThreeAKind")
    {
        for (int i = 0 ; i < arr.getCombinationList(3).size() ; i++)
        {
            if (arr.getCombinationList(3).at(i).getValue() > c.getValue())
            {
                // arr.getCombinationList(3)->at(i).printKombinasi();
                greaterComb.push_back(&arr.getCombinationList(3).at(i));
                // cout<<endl;
                this->canPlay = true;
            }
            else
            {
                // cout<<"Sayang sekali, Anda tidak memiliki kartu Kombo 3 yang lebih tinggi"<<endl;
            }
        }
    }
    else if (c.getCName() == "Pair")
    {
        for (int i = 0 ; i < arr.getCombinationList(2).size() ; i++)
        {
            if (arr.getCombinationList(2).at(i).getValue() > c.getValue())
            {
                // cout<<"HAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHHAHAHAHAHA"<<endl;
                // arr.getCombinationList(2).at(i).printKombinasi();
                greaterComb.push_back(&arr.getCombinationList(2).at(i));
                // cout<<"PRINT KOMBINASI"<<endl;
                // greaterComb.at(i)->printKombinasi();
                // cout<<endl;s
                // cout<<"PUSH"<<endl;
                // cout<<"PUSHGANPUSHGANPUSHGANPUSHGAN"<<endl;
                this->canPlay = true;
            }
            else
            {
                // cout<<"Sayang sekali, Anda tidak memiliki kartu Kombo 2 yang lebih tinggi"<<endl;
            }
        }
    }
    else if (c.getCName() == "HighCard")
    {
        for (int i = 0 ; i < arr.getCombinationList(1).size() ; i++)
        {
            if (arr.getCombinationList(1).at(i).getValue() > c.getValue())
            {
                // arr.getCombinationList(1).at(i).printKombinasi();
                greaterComb.push_back(&arr.getCombinationList(1).at(i));
                // cout<<endl;
                this->canPlay = true;
            }
            // else
            // {
            //     cout<<"Sayang sekali, Anda tidak memiliki kartu High Card yang lebih tinggi"<<endl;
            // }
        }
    }
}
ArrOfKombinasi* CapsaGamePlayer::getArrOfKombinasi()
{
    return &this->arr;
}   
bool CapsaGamePlayer::isGreater()
{
    return canPlay;
}
void CapsaGamePlayer::displayGreaterComb()
{
    for (int i = 0 ; i < greaterComb.size() ; i++) 
    {
        cout<<i+1<<". ";
        // greaterComb[i]->printKombinasi();
        // cout<<endl;
        // cout<<"================================================"<<endl;
        // cout<<greaterComb[i]->getCName()<<endl;
        // cout<<"------------------------------------------------"<<endl;
        // cout<<"UKURAN "<<endl;
        // cout<<greaterComb.size()<<endl;
        // for(int j = 0 ; j < greaterComb[i]->getCombinationCard().size() ; j++)
        // {
            // cout<<"TES"<<endl
            greaterComb[i]->printKombinasi();
        // }
        // cout<<endl;
        // cout<<"================================================"<<endl;
    }
}
int CapsaGamePlayer::getCountOfPlayerCards()
{
    return this->countOfPlayerCards;
}
KombinasiCapsa& CapsaGamePlayer::getGreaterComb(int i)
{
    return *greaterComb[i];
}

void CapsaGamePlayer::setArrCombination()
{
    this->arr = ArrOfKombinasi(getCard());
}