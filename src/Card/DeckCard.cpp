#include "DeckCard.hpp"

bool compareAngka(DeckCard c, DeckCard other){
    return (c.getNum()<other.getNum());
}

bool compareWarna(DeckCard c, DeckCard other){
    return (c.getType()<other.getType());
}

bool compareValue(DeckCard c, DeckCard other){
    return (c.value()<other.value());
}

DeckCard::DeckCard(){}

DeckCard::DeckCard(int t, int n):Warna(t), Angka(n) 
{
}
DeckCard::~DeckCard(){}

void DeckCard::printInfo()
{
    // concat getNum() and translateToString()
    string card = to_string(this->getNum()) + " " + this->translateToString();
    printColor pc;
    if (this->translateToString() == "Biru"){
        pc.printBlue(card);
    }else if (this->translateToString() == "Merah"){
        pc.printRed(card);
    }else if (this->translateToString() == "Kuning"){
        pc.printYellow(card);
    }else if (this->translateToString() == "Hijau"){
        pc.printGreen(card);
    }else{
        cout<< card <<endl;
    }
}
void DeckCard::printType()
{
    cout<<this->getNum()<<" "<<this->translateToType();
}
double DeckCard::value()
{
    double tempwarna;
    if (getType()==1)
    {
        tempwarna = 0;
    }
    else if(getType()==2)
    {
        tempwarna = 0.0001;
    }
    else if(getType()==3)
    {
        tempwarna = 0.001;
    }
    else
    {
        tempwarna = 0.01;
    }
    double temp_num = (double)this->getNum()/10.0;
    return temp_num + tempwarna;
}

bool DeckCard::operator<(DeckCard& other)
{
    double val1 = this->value();
    double val2 = other.value();
    return (val1<val2);
}

bool DeckCard::operator>(DeckCard& other){
    double val1 = this->value();
    double val2 = other.value();
    return (val1>val2);
}

bool DeckCard::operator==(DeckCard& other){
    double val1 = this->getNum();
    double val2 = other.getNum();
    return (val1==val2);
}

bool DeckCard::operator==(const DeckCard& other)const{
    double val1 = this->getNum();
    double val2 = other.getNum();
    return (val1==val2);
}

