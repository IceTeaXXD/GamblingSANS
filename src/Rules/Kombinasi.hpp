#ifndef KOMBINASI_HPP
#define KOMBINASI_HPP
#include <iostream>
#include "FindValue.hpp"
#include "../Card/DeckCard.hpp"

class Kombinasi : protected FindValue{
    private:
        DeckCard* playerCard1;
        DeckCard* playerCard2;
        DeckCard* tableCard1;
        DeckCard* tableCard2;
        DeckCard* tableCard3;
        DeckCard* tableCard4;
        DeckCard* tableCard5;

    public:
        /* Default Constructor */
        Kombinasi();
        ~Kombinasi();
        /* Setter */
        /* Set Kartu dari playerCards dan tableCards*/
        void setCards(DeckCardCollection playerCards, DeckCardCollection tableCards);

        /* Nentuin value kartu untuk kombinasi */
        int value();

        /* Bruteforcing untuk Kombinasi Kartu */
        int getCombination(DeckCard x, DeckCard tc);

        /* Operator overloading buat bandingin value */
        Kombinasi& operator>(Kombinasi&);
        Kombinasi& operator<(Kombinasi&);
        Kombinasi& operator==(Kombinasi&);

};

#endif
