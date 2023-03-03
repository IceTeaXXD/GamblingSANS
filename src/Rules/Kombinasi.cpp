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
    this->arr.push_back(playerCards.getCard(0));
    this->arr.push_back(playerCards.getCard(1));
    for(int i = 0 ; i < 5 ; i++)
    {
        this->arr.push_back(tableCards.getCard(i));
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

bool Kombinasi::isTwoPair()
{
    int count_pair = 0;
    vector<DeckCard> temp;
    for (int i = 0 ; i < 7 ; i++)
    {
        for (int j = i+1 ; j < 7 ; j++)
        {
            if(arr[i].getNum() == arr[j].getNum()){
                count_pair++;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
            }
            if(count_pair == 2){
                /* Ditemukan Two Pair */
                for(int i = 0;i<4;i++){
                    arrTwoPair.push_back(temp[i]);
                }
                return true;
            }
        }
    }
    return false;
}

bool Kombinasi::isThreeOfKind(){

    for(int i = 0; i < 7 ; i++){
        int temp_num = arr[i].getNum();
        vector<DeckCard> temp;
        temp.push_back(arr[i]);
        int count_same = 1;

        for (int j = i+1; j < 7; j++){
            if(temp_num == arr[j].getNum()){
                count_same++;
                temp.push_back(arr[j]);
            }
            if(count_same == 3){
                for(int k = 0; k < 3 ; k++){
                    arrThreeOfKind.push_back(temp[k]);
                }
                return true;
            }
        }

        if(count_same != 3){
            temp.clear();
            count_same = 0;
        }
    }

    return false;

}

bool Kombinasi::isFourAKind(){

    for(int i = 0; i < 7 ; i++){
        int temp_num = arr[i].getNum();
        vector<DeckCard> temp;
        temp.push_back(arr[i]);
        int count_same = 1;

        for (int j = i+1; j < 7; j++){
            if(temp_num == arr[j].getNum()){
                count_same++;
                temp.push_back(arr[j]);
            }
            if(count_same == 4){
                for(int k = 0; k < 4 ; k++){
                    arrThreeOfKind.push_back(temp[k]);
                }
                return true;
            }
        }

        if(count_same != 4){
            temp.clear();
            count_same = 0;
        }
    }

    return false;

}

bool Kombinasi::isStraight(){
    bool straight = false;
    sort(this->arr.begin(), this->arr.end(), DeckCard::compareAngka);
    for (int i = 4; i<this->arr.size(); i++)
    {
        if (this->arr[i].getNum()-this->arr[i-4].getNum()==4)
        {
            int temp = this->arr[i-4].getNum()-1;
            for(int j = i-4; j<i+1; j++)
            {
                if ((this->arr[j].getNum()-temp)==1)
                {
                    temp = this->arr[j].getNum();
                    this->arrStraight.push_back(this->arr[j]);
                }
                else
                {
                    this->arrStraight.clear();
                    straight = false;
                    break;
                }
            }
            if (straight)
            {
                return true;
            }
        }
    }
    return false;
}

bool Kombinasi::isFlush(){
    sort(this->arr.begin(), this->arr.end(), DeckCard::compareWarna);
    for (int i = 4; i<this->arr.size(); i++)
    {
        if (this->arr[i].getType()==this->arr[i-4].getType())
        {
            for (int j = i-4; j < i+1; j++){
                this->arrFlush.push_back(this->arr[i]);
            }
            return true;
        }
    }
    return false;
}