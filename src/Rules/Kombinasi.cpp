#include "Kombinasi.hpp"

template <class T, size_t n>
T maxArr(T (&arr) [n]){
    T maks = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i]>maks){
            maks = arr[i];
        }
    }
    return maks;
}

template <class T>
T maxArr (vector<T> arr){
    T maks = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i]>maks){
            maks = arr[i];
        }
    }
    return maks;
}

Kombinasi::Kombinasi(){}
Kombinasi::~Kombinasi(){}

void Kombinasi::setCards(DeckCardCollection playerCards, DeckCardCollection tableCards){
    this->playerCard1 = playerCards.getCard(0);
    this->playerCard2 = playerCards.getCard(1);
    this->tableCard1 = tableCards.getCard(0);
    this->tableCard2 = tableCards.getCard(1);
    this->tableCard3 = tableCards.getCard(2);
    this->tableCard4 = tableCards.getCard(3);
    this->tableCard5 = tableCards.getCard(4);
}

int Kombinasi::value(){
    /* Ini kayaknya mending terima satu kartu terus tentuin valuenya berapa */
    return 0;
}

/* Belum dikerjain */
Kombinasi& Kombinasi::operator<(Kombinasi& other){
    return *this;
}

Kombinasi& Kombinasi::operator>(Kombinasi& other){
    return *this;
}

Kombinasi& Kombinasi::operator==(Kombinasi& other){
    return *this;
}

