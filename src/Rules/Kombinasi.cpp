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

template<class T>
T maxVector(vector<T>& v)
{
    T temp = v[0];
    for (int i = 0 ; i < v.size() ; i++)
    {
        if (v[i]>temp)
        {
            temp = v[i];
        }
    }
    return temp;
}

// template <class T>
// T maxArr (vector<T> arr){
//     T maks = arr[0];
//     for (int i = 1; i < n; i++){
//         if (arr[i]>maks){
//             maks = arr[i];
//         }
//     }
//     return maks;
// }

Kombinasi::Kombinasi(){}
Kombinasi::~Kombinasi(){}

void Kombinasi::setCards(DeckCardCollection playerCards, DeckCardCollection tableCards){
    this->arr.push_back(*playerCards.getCard(0));
    this->arr.push_back(*playerCards.getCard(1));
    for(int i = 0 ; i < 5 ; i++)
    {
        this->arr.push_back(*tableCards.getCard(i));
    }
}

double Kombinasi::value(){
    /* Ini kayaknya mending terima satu kartu terus tentuin valuenya berapa */
    /*double temp = 
    looping dari atas (straight flush) buat cari nilainya
    if (temp == 0) 
    {
        temp =  HighCard();
    }
    return temp;
    */
   if (isPair())
   {
        DeckCard max = maxVector(arrPair);
        return (2 + max.getValue());
   }
   /*Implementasi kombinasi berlanjut*/
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

double Kombinasi::HighCard()
{ 
    /* rumus = konstanta/10 + (warna-1) * 0.3*/
    double ret1 = arr[0].getValue();
    double ret2 = arr[1].getValue();
    if (ret1>ret2)
    {
        return ret1;
    }
    else
    {
        return ret2;
    }
}

bool Kombinasi::isPair()
{
    for (int i = 0 ; i < 7 ; i++)
    {
        for (int j = i+1 ; j < 7 ; i++)
        {
            if(arr[i].getNum() == arr[j].getNum())
            {
                arrPair.push_back(arr[i]);
                arrPair.push_back(arr[j]);
                return true;
            }
        }
    }
    return false;
}
