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

// Belum dikerjain

DeckCard& DeckCard::operator<(DeckCard& other){
    return *this;
}

DeckCard& DeckCard::operator>(DeckCard& other){
    return *this;
}

DeckCard& DeckCard::operator==(DeckCard& other){
    return *this;
}



int Angka::getNum(){return this->num;}
Angka::Angka(){}
Angka::Angka(int num){
    this->num = num;
}
Warna::Warna(){}
Warna::Warna(int t){
    this->type = t;
}
int Warna::getType()
{
    return type;
}

DeckCardCollection::DeckCardCollection()
{
    vector<DeckCard> cards;
    for (int i = 0 ; i<4 ; i++)
    {
        for (int j = 0 ; j < 13; j++)
        {
            DeckCard* c = new DeckCard(i+1,j+1);
            cards.push_back(*c);
        }
    }

    /* Mengacak */
    srand(time(0));
    vector<int> num;
    for (int i = 1; i <= 52; i++){
        num.push_back(i);
    }
    for (int i = 0; i < 52; i++){
        int randIdx = rand() % (52 - i);
        this->buffer.push_back(cards[num[randIdx]-1]);
        num.erase(num.begin() + randIdx);
    }
}
void DeckCardCollection::TableCards(){
    /* Make 52 Deck Cards */
    vector<DeckCard> cards;
    for (int i = 0 ; i<4 ; i++)
    {
        for (int j = 0 ; j < 13; j++)
        {
            DeckCard* c = new DeckCard(i+1,j+1);
            cards.push_back(*c);
        }
    }

    /* Mengacak */
    srand(time(0));
    vector<int> num;
    for (int i = 1; i <= 52; i++){
        num.push_back(i);
    }
    for (int i = 0; i < 52; i++){
        int randIdx = rand() % (52 - i);
        this->buffer.push_back(cards[num[randIdx]-1]);
        num.erase(num.begin() + randIdx);
    }
}


DeckCardCollection::~DeckCardCollection(){}

DeckCard* DeckCardCollection::getCard(int a){
    return(&this->buffer[a]);
}

void DeckCardCollection::setCard(DeckCard& c){
    this->buffer.push_back(c);
}

DeckCard* DeckCardCollection::takeCard(){
    DeckCard* c = new DeckCard(this->buffer[0]);
    this->buffer.erase(this->buffer.begin());
    return c;
}

void DeckCardCollection::operator+(DeckCard& c){
    this->buffer.push_back(c);
}