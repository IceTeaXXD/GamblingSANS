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
        cout<< card;
    }
}

void DeckCard::printInfoCapsa()
{
    // concat getNum() and translateToString()
    string card = to_string(this->getNum()) + " " + this->translateToType();
    printColor pc;
    if (this->translateToString() == "Diamond"){
        pc.printRed(card);
    }else if (this->translateToString() == "Club"){
        pc.printBlue(card);
    }else if (this->translateToString() == "Heart"){
        pc.printRed(card);
    }else if (this->translateToString() == "Spade"){
        pc.printBlue(card);
    }else{
        cout<< card <<endl;
    }
}

void DeckCard::printType()
{
    stringstream buffer;
    string num;
    printColor pc;
    if (this->getNum()==11)
    num = "Jack";
    else if (this->getNum()==12)
    num = "Queen";
    else if (this->getNum()==13)
    num = "King";
    else
    num = to_string(this->getNum());
    string card = num + " ";
    buffer << std::left << std::setw(8) << std::setfill(' ') << card;
    if (this->translateToType() == "Diamond"){
        cout <<"♦️  "<< "\033[1;31m" << buffer.str() << "\033[0m";
    }else if (this->translateToType() == "Club"){
        cout <<"♣️  "<< "\033[1;34m" << buffer.str() << "\033[0m";
    }else if (this->translateToType() == "Heart"){
        cout <<"♥️  "<< "\033[1;31m" << buffer.str() << "\033[0m";
    }else if (this->translateToType() == "Spade"){
        cout<<"♠️  " << "\033[1;34m" << buffer.str() << "\033[0m";
    }
    buffer.str(std::string());
}

double DeckCard::value()
{
    double tempwarna;
    if (getType()==1)
    {
        tempwarna = 0.00001;
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

