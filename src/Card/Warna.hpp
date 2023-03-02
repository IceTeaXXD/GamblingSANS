#ifndef WARNA_HPP
#define WARNA_HPP
#include <iostream>
using namespace std;
class Warna{
    private:
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
        Warna(int);
        Warna();
};
#endif