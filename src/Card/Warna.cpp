#include "Warna.hpp"
string Warna::translateToString(){
    if(getType() == 1){
        return "Hijau";
    }else if (getType() == 2)
    {
        return "Biru";
    }else if(getType() == 3){
        return "Kuning";
    }else if(getType() == 4){
        return "Merah";
    }else{
        return "Hitam";
    }
}
string Warna::translateToType(){
    if(getType() == 1){
        return "Diamond";
    }else if (getType() == 2)
    {
        return "Club";
    }else if(getType() == 3){
        return "Heart";
    }else{
        return "Spade";
    }
}
Warna::Warna(){}
Warna::Warna(int t){
    this->type = t;
}
int Warna::getType()
{
    return type;
}

void Warna::setWarna(int t)
{
    this->type = t;
}