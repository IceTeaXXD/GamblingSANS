#include "CardCollection.hpp"
using namespace std;

template <class T>
CardCollection<T>::CardCollection(){}

template <class T>
void CardCollection<T>::MakeDeck(){}

template <>
void CardCollection<DeckCard>::MakeDeck(){
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

/* Buatan 13521024 */
template <>
void CardCollection<AbilityCard*>::MakeDeck(){
    AbilityCard* Reroll = new REROLL();
    AbilityCard* quadruple = new Quadruple();
    AbilityCard* quarter = new Quarter();
    AbilityCard* reverseDirection = new ReverseDirection();
    AbilityCard* swapCard = new SwapCard();
    AbilityCard* SWITCH = new Switch();
    AbilityCard* abilityless = new Abilityless();

    /* Mengacak Kartu */
    vector<AbilityCard*> cards;
    cards.push_back(Reroll);
    cards.push_back(quadruple);
    cards.push_back(quarter);
    cards.push_back(reverseDirection);
    cards.push_back(swapCard);
    cards.push_back(SWITCH);
    cards.push_back(abilityless);

    srand(time(0));
    vector<int> num;
    for (int i = 1; i <= 7; i++){
        num.push_back(i);
    }
    for (int i = 0; i < 7; i++){
        int randIdx = rand() % (7 - i);
        this->buffer.push_back(cards[num[randIdx]-1]);
        num.erase(num.begin() + randIdx);
    }
}

template <class T>
void CardCollection<T>::MakeDeck(string filename){}

template <>
void CardCollection<DeckCard>::MakeDeck(string filename){
    /* 
        FORMAT FILE 
        n # Jumlah Kartu
        w1 a1 # Warna kartu 1, Angka 1
        w2 a2 # Warna kartu 2, Angka 2

        Angka dari 1-10, A, K, Q, J
    */

    string out;

    ifstream File(filename);

    /* Compute number of cards */
    getline(File, out);
    int n = stoi(out);

    for(int i = 0; i < n ; i++){
        getline(File, out);
        int count = 0;
        int w,a;
        for (auto x : out){
            if(x == ' '){
                /* PASS */
            }else{
                count += 1;
                if(count == 1){
                    w = x - '0';
                }else{
                    if(x == 'A'){
                        a = 10;
                    }else if(x=='K'){
                        a = 11;
                    }else if (x == 'Q'){
                        a = 12;
                    }else if(x == 'J'){
                        a = 13;
                    }else{
                        a = x - '0';
                    }
                }
            }
        }

        if(w > 0 && w <= 4 && a > 0 && a <= 13){
            buffer.push_back(DeckCard(w,a));
        }else{
            throw "Salah format. Perhatikan warna dan angka yang dimasukkan!\n";
        }
    }

    File.close();
}

template <class T>
CardCollection<T>::~CardCollection(){}

template <class T>
T CardCollection<T>::getCard(int a){
    return(this->buffer[a]);
}

template <class T>
void CardCollection<T>::setCard(T& c){
    this->buffer.push_back(c);
}

template <class T>
T CardCollection<T>::takeCard(){
    T c = T(this->buffer[0]);
    this->buffer.erase(this->buffer.begin());
    // cout<<"Kamu dapat kartu "<<c->getNum()<<" "<<c->getType()<<endl;
    //Get Type perlu dibikin supaya per warnanya yang keluar bukan angka
    return c;
}

template <class T>
void CardCollection<T>::operator+(T& c){
    this->buffer.push_back(c);
}

template <class T>
void CardCollection<T>::displayDeckCard()
{
    for (auto it = buffer.begin(); it != buffer.end(); it++) 
    {
        it->printInfo();
    }
}

// template <class T>
// void CardCollection<T>::displayCapsa()
// {
//     cout<<"[";
//     for (auto it = buffer.begin(); it != buffer.end(); it++) 
//     {
//         it->printType();
//     }
//     cout<<"]";
// }
template <>
void CardCollection<AbilityCard*>::displayDeckCard()
{
    // for (auto it = buffer.begin(); it != buffer.end(); it++) 
    // {
    //     it[]->printInfo();
    // }
}

template <class T>
void CardCollection<T>::clear(){
    this->buffer.clear();
}

template <class T>
void CardCollection<T>::addCard(T& add)
{
    this->buffer.push_back(add);
}