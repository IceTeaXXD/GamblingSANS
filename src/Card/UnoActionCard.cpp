#include "UnoActionCard.hpp"

plus2::plus2(){}

plus2::plus2(int t){
    this->type = t;
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

wildcard::wildcard(){}

void wildcard::printInfo(){
    cout << "WILDCARD";
}

wildcardplus4::wildcardplus4(){}

void wildcardplus4::printInfo(){
    cout << "WILDCARD +4";
}