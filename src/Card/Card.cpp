#include "Card.hpp"

Card::Card(){}

DeckCard::DeckCard(int n):num(rand() % 13 + 1){}
DeckCard::~DeckCard(){}
int DeckCard::getNum(){return this->num;}
int DeckCard::getType(){return this->type;}

AbilityCard::AbilityCard(int type):type(type){}
int AbilityCard::getType(){return this->type;}