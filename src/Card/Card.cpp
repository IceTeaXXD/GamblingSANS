#include "Card.hpp"
#include "AbilityCard.hpp"

Card::Card(){}

DeckCard::DeckCard(int n):num(rand() % 13 + 1){}
DeckCard::~DeckCard(){}
int DeckCard::getNum(){return this->num;}
int DeckCard::getType(){return this->type;}