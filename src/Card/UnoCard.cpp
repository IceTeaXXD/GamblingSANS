#include "UnoCard.hpp"

UnoCard::UnoCard(){}

UnoCard::UnoCard(int num, int type) : Angka(num), Warna(type){}

void UnoCard::printInfo(){
    cout<<this->getNum()<<" "<<this->translateToString()<<endl;
}