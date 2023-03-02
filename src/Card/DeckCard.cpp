#include "DeckCard.hpp"

DeckCard::DeckCard(){}

DeckCard::DeckCard(int t, int n):Warna(t), Angka(n) 
{
}
DeckCard::~DeckCard(){}

void DeckCard::printInfo()
{
    cout<<this->getNum()<<" "<<this->translateToString()<<endl;
}

// Belum dikerjain

DeckCard& DeckCard::operator<(DeckCard& other){
    return *this;
}

DeckCard& DeckCard::operator>(DeckCard& other){
    return *this;
}

DeckCard& DeckCard::operator==(DeckCard& other){
    return *this;
}