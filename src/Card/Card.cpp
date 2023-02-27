#include "Card.hpp"
#include "AbilityCard.hpp"

Card::Card(){}

string Card::getType(){}
int Card::getNum(){}
void Card::printInfo(){cout<<"TES TES"<<endl;}

DeckCard::DeckCard(){}
DeckCard::DeckCard(int t, int n)  
{
    this->type = t;
    this->num = n;
}
DeckCard::~DeckCard(){}
void DeckCard::printInfo()
{
    cout<<this->getNum()<<" "<<this->getType()<<endl;
}
int DeckCard::getNum(){return this->num;}
string DeckCard::getType()
{
    string ret;
    if (this->type == 1)
    {
        ret = "Hijau";
    }
    else if (this->type == 2)
    {
        ret = "Biru";
    }
    else if (this->type == 3)
    {
        ret = "Kuning";
    }
    else
    {
        ret = "Merah";
    }
    return ret;
}