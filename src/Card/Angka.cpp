#include <iostream>
#include "Angka.hpp"

int Angka::getNum(){return this->num;}
const int Angka::getNum() const {return this->num;}
Angka::Angka(){}
Angka::Angka(int num){
    this->num = num;
}