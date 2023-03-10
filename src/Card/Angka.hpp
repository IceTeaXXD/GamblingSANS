#ifndef ANGKA_HPP
#define ANGKA_HPP
#include <iostream>
using namespace std;

class Angka{
    protected:
        int num;
    public:
        void setNum(int);
        int getNum();
        Angka(int);
        Angka();
};

#endif