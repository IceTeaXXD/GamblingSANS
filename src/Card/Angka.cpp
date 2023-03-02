#include <iostream>
#include "Angka.hpp"

int Angka::getNum(){return this->num;}
Angka::Angka(){}
Angka::Angka(int num){
    this->num = num;
}