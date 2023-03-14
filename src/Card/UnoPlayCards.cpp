#include "UnoPlayCards.hpp"

UnoPlayCards::UnoPlayCards(){}

UnoPlayCards::UnoPlayCards(int t, int n) : Angka(t), Warna(n){
    cardType = "Play";
}

void UnoPlayCards::printInfo(){
    string card = to_string(this->getNum()) + " " + this->translateToString();
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