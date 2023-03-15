#ifndef KOMBINASICAPSA_HPP
#define KOMBINASICAPSA_HPP

#include "Kombinasi.hpp"
#include<vector>

class KombinasiCapsa : public Kombinasi{
    public :
        // ctor, dtor
        KombinasiCapsa();
        KombinasiCapsa(vector<DeckCard>,int);
        ~KombinasiCapsa();
        
        //function
        double getConst(int);
        KombinasiCapsa& operator=(const KombinasiCapsa&);
        
        //function override
        bool isPair();
        bool isTwoPair();
        bool isThreeOfKind();
        bool isStraight();
        bool isFlush();
        bool isFullHouse();
        bool isStraightFlush();
        bool isDragon();
};

#endif