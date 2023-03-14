#include "UnoActionCard.hpp"

plus2::plus2(){}

plus2::plus2(int t){
    this->type = t;
    this->cardType = "Plus2";
}

void plus2::printInfo(){
    string card = "Plus 2 " + this->translateToString();
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

reversecard::reversecard(){}

reversecard::reversecard(int t){
    this->type = t;
    this->cardType = "Reverse";
}

void reversecard::printInfo(){
    string card = "Reverse " + this->translateToString();
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

skip::skip(){}

skip::skip(int t){
    this->type = t;
    this->cardType = "Skip";
}

void skip::printInfo(){
    string card = "Skip " + this->translateToString();
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

wildcard::wildcard(){
    setWarna(0);
    this->cardType = "Wildcard";
}

void wildcard::printInfo(){
    cout << "WILDCARD";
}

wildcardplus4::wildcardplus4(){
    setWarna(0);
    this->cardType = "Wildcard+4";
}

void wildcardplus4::printInfo(){
    cout << "WILDCARD +4";
}