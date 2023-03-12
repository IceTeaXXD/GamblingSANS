#ifndef WARNA_HPP
#define WARNA_HPP
#include <iostream>
using namespace std;
class Warna{
    protected:
        /* Type 
        1. Hijau
        2. Biru
        3. Kuning
        4. Merah */
        int type;
    public:
        void setWarna(string);
        int getType();
        string translateToString();
        string translateToType();
        Warna(int);
        Warna();
};
#endif