#include "DeckCard.hpp"
int DeckCard::countofCards = 0;

DeckCard::DeckCard(){}

DeckCard::DeckCard(int t, int n):Warna(int t), Angka(int n) 
{
    countofCards++;
}
DeckCard::~DeckCard(){}

void DeckCard::printInfo()
{
    cout<<this->getNum()<<" "<<this->getType()<<endl;
}

int Angka::getNum(){return this->num;}

Angka::Angka(int num){
    this->num = num;
}

Warna::Warna(int t){
    this->type = type;
}
string Warna::getType()
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