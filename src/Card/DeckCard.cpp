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

double DeckCard::getValue()
{
    return this->getNum()/10 + (this->getType()-1)*0.3;
}

bool DeckCard::operator<(DeckCard& other)
{
    double val1 = this->getValue();
    double val2 = other.getValue();
    return (val1<val2);
}

bool DeckCard::operator>(DeckCard& other){
    double val1 = this->getValue();
    double val2 = other.getValue();
    return (val1>val2);
}

bool DeckCard::operator==(DeckCard& other){
    double val1 = this->getValue();
    double val2 = other.getValue();
    return (val1==val2);
}

bool DeckCard::compareAngka(DeckCard& other){
    return (this->getNum()<other.getNum());
}

bool DeckCard::compareWarna(DeckCard& other){
    return (this->getType()<other.getType());
}