#include "Kombinasi.hpp"

template <class T>
T maxArr(T* arr, int n){
    if (n==0)
    {
        return "Array Kosong\n";
    }
    else
    {
        T maks = arr[0];
        for (int i = 1; i < n; i++){
            if (arr[i]>maks){
                maks = arr[i];
            }
        }
        return maks;
    }
}

template <class T, size_t n>
T maxArr(T (&arr) [n]){
    if (n==0)
    {
        return "Array Kosong\n";
    }
    else
    {
        T maks = arr[0];
        for (int i = 1; i < n; i++){
            if (arr[i]>maks){
                maks = arr[i];
            }
        }
        return maks;
    }
}


Kombinasi::Kombinasi(){}
Kombinasi::Kombinasi(DeckCardCollection playerCards, DeckCardCollection tableCards)
{
    this->arr.push_back(playerCards.getCard(0));
    this->arr.push_back(playerCards.getCard(1));
    for(int i = 0 ; i < 5 ; i++)
    {
        this->arr.push_back(tableCards.getCard(i));
    }
}
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
   double val;
   if (isStraightFlush())
   {
        val = MAX_FOUR_KIND;
        for (DeckCard i : arrStraightFlush)
        {
            val += i.value();
        }
        return val;
   }
   else if (isFourAKind())
   {
        val = MAX_FULL_HOUSE;
        for (DeckCard i : arrFourAKind)
        {
            val += i.value();
        }
        return val;
   }
   else if (isFullHouse())
   {
        val = MAX_FLUSH;
        for (DeckCard i : arrFullHouse)
        {
            val += i.value();
        }
        return val;
   }
   else if (isFlush())
   {
        val = MAX_STRAIGHT;
        for (DeckCard i : arrFlush)
        {
            val += i.value();
        }
        return val;
   }
   else if (isStraight())
   {
        val = MAX_THREE_KIND;
        for (DeckCard i : arrStraight)
        {
            val += i.value();
        }
        return val;
   }
   else if (isThreeOfKind())
   {
        val = MAX_TWO_PAIR;
        for (DeckCard i : arrThreeOfKind)
        {
            val += i.value();
        }
        return val;
   }
   else if (isTwoPair())
   {
        val = MAX_PAIR;
        for (DeckCard i : arrTwoPair)
        {
            val += i.value();
        }
        return val;
   }
   else if (isPair())
   {
        val = MAX_HIGH_CARD;
        for (DeckCard i : arrPair)
        {
            val += i.value();
        }
        return val;
   }
   else
   {
        val = max_element(arr.begin(), arr.end(), compareValue)->value();
        return val;
   }
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

// double Kombinasi::HighCard()
// { 
//     /* rumus = konstanta/10 + (warna-1) * 0.3*/
//     double ret1 = arr[0].value();
//     double ret2 = arr[1].value();
//     if (ret1>ret2)
//     {
//         return ret1;
//     }
//     else
//     {
//         return ret2;
//     }
// }
string Kombinasi::getCombinationName()
{
    double val;
    if (isStraightFlush())
    {
        return "Straight Flush";
    }
    else if (isFourAKind())
    {
        return "Four a kind";
    }
    else if (isFullHouse())
    {
        return "Full House";
    }
    else if (isFlush())
    {
        return "Flush";
    }
    else if (isStraight())
    {
        return "Straight";
    }
    else if (isThreeOfKind())
    {
        return "Three of kind";
    }
    else if (isTwoPair())
    {
        return "Two Pair";
    }
    else if (isPair())
    {
        return "Pair";
    }
    else
    {
        return "High Card";
    }
}
bool Kombinasi::isPair()
{   
    sort(arr.begin(), arr.end(), compareAngka);
    for (int i = this->arr.size()-1; i>0; i--)
    {
        if(arr[i]==arr[i-1])
        {
            arrPair.push_back(arr[i]);
            arrPair.push_back(arr[i-1]);
            return true;
        }
    }
    return false;
    // for (int i = 0 ; i < 7 ; i++)
    // {
    //     for (int j = i+1 ; j < 7 ; i++)
    //     {
    //         if(arr[i].getNum() == arr[j].getNum())
    //         {
    //             arrPair.push_back(arr[i]);
    //             arrPair.push_back(arr[j]);
    //             return true;
    //         }
    //     }
    // }
    // return false;
}

bool Kombinasi::isTwoPair()
{   
    sort(arr.begin(), arr.end(), compareAngka);
    for (int i = this->arr.size()-1; i>0; i--)
    {
        if(arr[i]==arr[i-1])
        {
            for (int j = i-1; i>0; i--)
            {
                if (!(arr[j]==arr[i]) && (arr[j]==arr[j-1]))
                {
                    arrTwoPair.push_back(arr[i]);
                    arrTwoPair.push_back(arr[i-1]);
                    arrTwoPair.push_back(arr[j]);
                    arrTwoPair.push_back(arr[j-1]);
                    return true;
                }
            }
        }
    }
    return false;
    // int count_pair = 0;
    // vector<DeckCard> temp;
    // for (int i = 0 ; i < 7 ; i++)
    // {
    //     for (int j = i+1 ; j < 7 ; j++)
    //     {
    //         if(arr[i].getNum() == arr[j].getNum()){
    //             count_pair++;
    //             temp.push_back(arr[i]);
    //             temp.push_back(arr[j]);
    //         }
    //         if(count_pair == 2){
    //             /* Ditemukan Two Pair */
    //             for(int i = 0;i<4;i++){
    //                 arrTwoPair.push_back(temp[i]);
    //             }
    //             return true;
    //         }
    //     }
    // }
    // return false;
}

bool Kombinasi::isThreeOfKind(){

    sort(arr.begin(), arr.end(), compareAngka);
    for (int i = this->arr.size()-1; i>1; i--)
    {
        if (arr[i]==arr[i-2])
        {
            arrThreeOfKind.push_back(arr[i]);
            arrThreeOfKind.push_back(arr[i-1]);
            arrThreeOfKind.push_back(arr[i-2]);
        }
        return true;
    }
    return false;
    // for(int i = 0; i < 7 ; i++){
    //     int temp_num = arr[i].getNum();
    //     vector<DeckCard> temp;
    //     temp.push_back(arr[i]);
    //     int count_same = 1;

    //     for (int j = i+1; j < 7; j++){
    //         if(temp_num == arr[j].getNum()){
    //             count_same++;
    //             temp.push_back(arr[j]);
    //         }
    //         if(count_same == 3){
    //             for(int k = 0; k < 3 ; k++){
    //                 arrThreeOfKind.push_back(temp[k]);
    //             }
    //             return true;
    //         }
    //     }

    //     if(count_same != 3){
    //         temp.clear();
    //         count_same = 0;
    //     }
    // }

    // return false;

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
    sort(this->arr.begin(), this->arr.end(), compareAngka);
    for (int i = this->arr.size()-1; i>3; i--)
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
    sort(this->arr.begin(), this->arr.end(), compareWarna);
    for (int i = this->arr.size()-1; i>3; i--)
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

bool Kombinasi::isStraightFlush(){
    bool straight = false;
    sort(this->arr.begin(), this->arr.end(), compareAngka);
    for (int i = this->arr.size()-1; i>3; i--)
    {
        if (this->arr[i].getNum()-this->arr[i-4].getNum()==4)
        {
            int tempNum = this->arr[i-4].getNum()-1;
            int tempType = this->arr[i-4].getType();
            for(int j = i-4; j<i+1; j++)
            {
                if (((this->arr[j].getNum()-tempNum)==1)&&(this->arr[j].getType()==tempType))
                {
                    tempNum = this->arr[j].getNum();
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

bool Kombinasi::isFullHouse(){
    bool threeKind = false;
    bool fullHouse = false;
    vector<DeckCard> tempThreeKind;
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
                    tempThreeKind.push_back(temp[k]);
                }
                threeKind = true;
                break ;
            }
        }
        if (threeKind)
        {
            break;
        }
        if(count_same != 3){
            temp.clear();
            count_same = 0;
        }
    }

    if (threeKind)
    {
        for (int i = 0 ; i < 7 ; i++)
        {
            for (int j = i+1 ; j < 7 ; i++)
            {
                if(arr[i] == arr[j])
                {
                    if (!(arr[i]==tempThreeKind[0]))
                    {
                        fullHouse = true;
                        break;
                    }
                }
            }
            if (fullHouse)
            break;
        }
    }

    return fullHouse;
}