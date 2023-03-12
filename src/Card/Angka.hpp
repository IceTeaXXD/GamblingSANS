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
        const int getNum() const;
        Angka(int);
        Angka();
};

#endif