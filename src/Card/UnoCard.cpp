#include "UnoCard.hpp"

UnoCard::UnoCard(){}

UnoCard::UnoCard(int angka, int warna) : Angka(angka), Warna(warna){}

UnoCard::~UnoCard(){}

void UnoCard::printInfo(){
    cout << "Ini adalah kartu Uno" << endl;
}

void UnoCard::setCardType(string cardType){
    this->cardType = cardType;
}

string UnoCard::getCardType(){
    return this->cardType;
}