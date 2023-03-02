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
    if(val1<val2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DeckCard::operator>(DeckCard& other){
    double val1 = this->getValue();
    double val2 = other.getValue();
    if(val1>val2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DeckCard::operator==(DeckCard& other){
    double val1 = this->getValue();
    double val2 = other.getValue();
    if(val1==val2)
    {
        return true;
    }
    else
    {
        return false;
    }
}