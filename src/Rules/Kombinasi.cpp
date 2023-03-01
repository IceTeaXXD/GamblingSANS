#include "Kombinasi.hpp"

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