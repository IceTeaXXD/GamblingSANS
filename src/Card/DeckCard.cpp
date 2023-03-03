#include "DeckCard.hpp"

bool compareAngka(DeckCard c, DeckCard other){
    return (c.getNum()<other.getNum());
}

bool compareWarna(DeckCard c, DeckCard other){
    return (c.getType()<other.getType());
}

bool compareValue(DeckCard c, DeckCard other){
    return (c.getValue()<other.getValue());
}

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
    double val1 = this->getNum();
    double val2 = other.getNum();
    return (val1==val2);
}

