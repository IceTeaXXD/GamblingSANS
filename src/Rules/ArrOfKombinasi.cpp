#include "ArrOfKombinasi.hpp"
using namespace std;

ArrOfKombinasi::ArrOfKombinasi(){}

ArrOfKombinasi::~ArrOfKombinasi()
{
    arr.clear();
}

Kombinasi& ArrOfKombinasi::getKombinasi(int idx)
{
    //Implementasi hapus kombinasi ke idx
}

void ArrOfKombinasi::addKombinasi(Kombinasi& k)
{
    arr.push_back(k);
}