#include "UnoCard.hpp"

UnoCard::UnoCard(){}

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