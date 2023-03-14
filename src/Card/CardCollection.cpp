#include "CardCollection.hpp"
#include "../Exception/Exception.hpp"
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

template <>
void CardCollection<UnoCard*>::MakeDeck(){
    vector<UnoCard*> cards;

    /* Create Play Cards*/
    for(int i = 0 ; i <= 9 ; i++){
        for (int j = 1 ; j <= 4 ; j++){
            if (i == 0){ // 0 cards only 1 for each color
                UnoCard* c = new UnoPlayCards(0, j);
                cards.push_back(c);
            }else{ // 1-9 cards 2 for each color
                UnoCard* d = new UnoPlayCards(i, j);
                cards.push_back(d);
                UnoCard* e = new UnoPlayCards(i, j);
                cards.push_back(e);
            }
        }
    }

    /* Create Skip, Reverse, Plus 2 : 1 for each color*/
    for (int i = 1 ; i <= 4 ; i++){
        UnoCard*f = new plus2(i);
        cards.push_back(f);
        f = new plus2(i);
        cards.push_back(f);
        UnoCard*g = new skip(i);
        cards.push_back(g);
        g = new skip(i);
        cards.push_back(g);
        UnoCard*h = new reversecard(i);
        cards.push_back(h);
        h = new reversecard(i);
        cards.push_back(h);
    }

    /* Create WildCard and WildCard Plus 4*/
    for (int i = 0 ; i < 4 ; i++){
        UnoCard* k = new wildcard();
        cards.push_back(k);
        UnoCard* l = new wildcardplus4();
        cards.push_back(l);
    }

    /* Mengacak Kartu */
    srand(time(0));
    vector<int> num;
    for (int i = 1; i <= 108; i++){
        num.push_back(i);
    }
    for (int i = 0; i < 108; i++){
        int randIdx = rand() % (108 - i);
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

    vector<DeckCard> cards;

    string out;

    ifstream File("../config/"+filename);

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
            DeckCard* c = new DeckCard(w,a);
            cards.push_back(*c);
        }else{
            throw SalahFormatFile();
        }
    }
    /* Mengacak */
    srand(time(0));
    vector<int> num;
    for (int i = 1; i <= n; i++){
        num.push_back(i);
    }
    for (int i = 0; i < n; i++){
        int randIdx = rand() % (n - i);
        this->buffer.push_back(cards[num[randIdx]-1]);
        num.erase(num.begin() + randIdx);
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
void CardCollection<T>::operator-(T& ret){
    ret = T(this->buffer[0]);
    this->buffer.erase(this->buffer.begin());
    // cout<<"Kamu dapat kartu "<<c->getNum()<<" "<<c->getType()<<endl;
    //Get Type perlu dibikin supaya per warnanya yang keluar bukan angka
}

template <class T>
void CardCollection<T>::operator+(T& c){
    this->buffer.push_back(c);
}

template<>
void CardCollection<UnoCard*>::displayDeckCard(){
    for (int i = 0 ; i < this->buffer.size() ; i++){
        this->buffer[i]->printInfo();
        cout << endl;
    }
}

template <class T>
void CardCollection<T>::Del(T& el)
{
    auto it = std::find(buffer.begin(), buffer.end(), el);
    if (it != buffer.end())
    {
        buffer.erase(it); // corrected line
        cout<<"Berhasil menghapus elemen"<<endl;
    }
    else
    {
        cout<<"Value not found"<<endl;
    }
}

template <class T>
void CardCollection<T>::displayDeckCard()
{
    for (auto it = buffer.begin(); it != buffer.end(); it++) 
    {
        it->printInfo();
        cout << endl;
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
vector<T> CardCollection<T>::getBuffer(){
    return this->buffer;
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

template <class T>
T& CardCollection<T>::getLeftCard(){
    return this->buffer[0];
}

template <class T>
T& CardCollection<T>::getRightCard(){
    return this->buffer[1];
}

template <class T>
void CardCollection<T>::setLeftCard(T& c){
    this->buffer[0] = c;
}

template <class T>
void CardCollection<T>::setRightCard(T& c){
    this->buffer[1] = c;
}