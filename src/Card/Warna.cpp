#include "Warna.hpp"
string Warna::translateToString(){
    if(getType() == 1){
        return "Hijau";
    }else if (getType() == 2)
    {
        return "Biru";
    }else if(getType() == 3){
        return "Kuning";
    }else{
        return "Merah";
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