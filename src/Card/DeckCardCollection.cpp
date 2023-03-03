#include "DeckCardCollection.hpp"
using namespace std;

DeckCardCollection::DeckCardCollection(){}

void DeckCardCollection::MakeDeck(){
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

// void DeckCardCollection::TableCards(){
//     /* Make 52 Deck Cards */
//     vector<DeckCard> cards;
//     for (int i = 0 ; i<4 ; i++)
//     {
//         for (int j = 0 ; j < 13; j++)
//         {
//             DeckCard* c = new DeckCard(i+1,j+1);
//             cards.push_back(*c);
//         }
//     }

//     /* Mengacak */
//     srand(time(0));
//     vector<int> num;
//     for (int i = 1; i <= 52; i++){
//         num.push_back(i);
//     }
//     for (int i = 0; i < 52; i++){
//         int randIdx = rand() % (52 - i);
//         this->buffer.push_back(cards[num[randIdx]-1]);
//         num.erase(num.begin() + randIdx);
//     }
// }



DeckCardCollection::~DeckCardCollection(){}

DeckCard DeckCardCollection::getCard(int a){
    return(this->buffer[a]);
}

void DeckCardCollection::setCard(DeckCard& c){
    this->buffer.push_back(c);
}

DeckCard DeckCardCollection::takeCard(){
    DeckCard c = DeckCard(this->buffer[0]);
    this->buffer.erase(this->buffer.begin());
    // cout<<"Kamu dapat kartu "<<c->getNum()<<" "<<c->getType()<<endl;
    //Get Type perlu dibikin supaya per warnanya yang keluar bukan angka
    return c;
}

void DeckCardCollection::operator+(DeckCard& c){
    this->buffer.push_back(c);
}
void DeckCardCollection::displayDeckCard()
{
    for (auto it = buffer.begin(); it != buffer.end(); it++) 
    {
        it->printInfo();
    }
}

void DeckCardCollection::clear(){
    this->buffer.clear();
}
void DeckCardCollection::addCard(DeckCard& add)
{
    this->buffer.push_back(add);
}