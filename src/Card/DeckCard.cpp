#include "DeckCard.hpp"

DeckCard::DeckCard(){}

DeckCard::DeckCard(int t, int n):Warna(t), Angka(n) 
{
}
DeckCard::~DeckCard(){}

void DeckCard::printInfo()
{
    cout<<this->getNum()<<" "<<this->getType()<<endl;
}

int Angka::getNum(){return this->num;}

Angka::Angka(int num){
    this->num = num;
}

Warna::Warna(int t){
    this->type = type;
}
int Warna::getType()
{
    return type;
}

DeckCardCollection::DeckCardCollection(){
    /* Make 52 Deck Cards */
    for (int i = 0 ; i<4 ; i++)
    {
        for (int j = 0 ; j < 13; j++)
        {
            DeckCard* c = new DeckCard(i+1,j+1);
        }
        this->buffer.push_back(*c);
    }

    /* Mengacak */
    vector<DeckCard> acak;
    for(int i = 0; i < 52; i++){
        DeckCard* c = this->buffer[Rand() % 52];
        while(find(acak.begin(), acak.end(), *c) != acak.end()){
            *c = this->buffer[Rand() % 52];
        }
        acak.push_back(*c);
    }
}

DeckCardCollection::~DeckCardCollection(){}

DeckCard DeckCardCollection::getCard(int i){
    return(this->buffer[i]);
}