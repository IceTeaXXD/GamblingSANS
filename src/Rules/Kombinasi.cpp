#include "Kombinasi.hpp"

template <class T>
T maxArr(T* arr, int n){
    T maks = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i]>maks){
            maks = arr[i];
        }
    }
    return maks;
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
Kombinasi::Kombinasi(CardCollection<DeckCard> playerCards, CardCollection<DeckCard> tableCards)
{
    this->arr.push_back(playerCards.getCard(0));
    this->arr.push_back(playerCards.getCard(1));
    for(int i = 0 ; i < 5 ; i++)
    {
        this->arr.push_back(tableCards.getCard(i));
    }
}
Kombinasi::~Kombinasi(){}

void Kombinasi::setCards(CardCollection<DeckCard> playerCards, CardCollection<DeckCard> tableCards){
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
   cout<<"SIG"<<endl;
   double val;
   if (isStraightFlush() && !isTableCardStraightFlush())
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
        cout<<arrThreeOfKind.size()<<endl;
        for (auto i : arrThreeOfKind)
        {
            cout<<"HELO"<<endl;
            i.printInfo();
            val += i.value();
        }
        cout<<"tolol";
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
        cout<<MAX_FOUR_KIND<<endl;
        return "Straight Flush";
    }
    else if (isFourAKind())
    {
        cout<<MAX_FULL_HOUSE<<endl;
        return "Four a kind";
    }
    else if (isFullHouse())
    {
        cout<<MAX_FLUSH<<endl;
        return "Full House";
    }
    else if (isFlush())
    {
        cout<<MAX_STRAIGHT<<endl;
        return "Flush";
    }
    else if (isStraight())
    {
        cout<<MAX_THREE_KIND<<endl;
        return "Straight";
    }
    else if (isThreeOfKind())
    {
        cout<<MAX_TWO_PAIR<<endl;
        return "Three of kind";
    }
    else if (isTwoPair())
    {
        cout<<MAX_PAIR<<endl;
        return "Two Pair";
    }
    else if (isPair())
    {
        cout<<MAX_HIGH_CARD<<endl;
        return "Pair";
    }
    else
    {
        cout<<'0'<<endl;
        return "High Card";
    }
}
bool Kombinasi::isPair()
{   
    vector<DeckCard> tempArr = arr;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>0; i--)
    {
        if(tempArr[i]==tempArr[i-1])
        {
            arrPair.push_back(tempArr[i]);
            arrPair.push_back(tempArr[i-1]);
            return true;
        }
    }
    return false;
    // for (int i = 0 ; i < tempArr.size() ; i++)
    // {
    //     for (int j = i+1 ; j < tempArr.size() ; i++)
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

bool Kombinasi::isTableCardPair()
{   
    auto first = arr.begin() + 2;
    auto last = arr.end() - 1;
    vector<DeckCard> tempArr(first, last);
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>0; i--)
    {
        if(tempArr[i]==tempArr[i-1])
        {
            arrPair.push_back(tempArr[i]);
            arrPair.push_back(tempArr[i-1]);
            return true;
        }
    }
    return false;
    // for (int i = 0 ; i < tempArr.size() ; i++)
    // {
    //     for (int j = i+1 ; j < tempArr.size() ; i++)
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
    vector<DeckCard> tempArr = arr;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>0; i--)
    {
        if(tempArr[i]==tempArr[i-1])
        {
            for (int j = i-1; j>0; j--)
            {
                if (!(tempArr[j]==tempArr[i]) && (tempArr[j]==tempArr[j-1]))
                {
                    arrTwoPair.push_back(tempArr[i]);
                    arrTwoPair.push_back(tempArr[i-1]);
                    arrTwoPair.push_back(tempArr[j]);
                    arrTwoPair.push_back(tempArr[j-1]);
                    return true;
                }
            }
        }
    }
    return false;
    // int count_pair = 0;
    // vector<DeckCard> temp;
    // for (int i = 0 ; i < tempArr.size() ; i++)
    // {
    //     for (int j = i+1 ; j < tempArr.size() ; j++)
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

bool Kombinasi::isTableCardTwoPair()
{   
    auto first = arr.begin() + 2;
    auto last = arr.end() - 1;
    vector<DeckCard> tempArr(first, last);
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>0; i--)
    {
        if(tempArr[i]==tempArr[i-1])
        {
            for (int j = i-1; i>0; i--)
            {
                if (!(tempArr[j]==tempArr[i]) && (tempArr[j]==tempArr[j-1]))
                {
                    arrTwoPair.push_back(tempArr[i]);
                    arrTwoPair.push_back(tempArr[i-1]);
                    arrTwoPair.push_back(tempArr[j]);
                    arrTwoPair.push_back(tempArr[j-1]);
                    return true;
                }
            }
        }
    }
    return false;
    // int count_pair = 0;
    // vector<DeckCard> temp;
    // for (int i = 0 ; i < tempArr.size() ; i++)
    // {
    //     for (int j = i+1 ; j < tempArr.size() ; j++)
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
    vector<DeckCard> tempArr = arr;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>1; i--)
    {
        if (tempArr[i]==tempArr[i-2])
        {
            arrThreeOfKind.push_back(tempArr[i]);
            arrThreeOfKind.push_back(tempArr[i-1]);
            arrThreeOfKind.push_back(tempArr[i-2]);
            return true;
        }
    }
    return false;
}

bool Kombinasi::isTableCardThreeOfKind(){
    auto first = arr.begin() + 2;
    auto last = arr.end() - 1;
    vector<DeckCard> tempArr(first, last);
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>1; i--)
    {
        if (tempArr[i]==tempArr[i-2])
        {
            arrThreeOfKind.push_back(tempArr[i]);
            arrThreeOfKind.push_back(tempArr[i-1]);
            arrThreeOfKind.push_back(tempArr[i-2]);
            return true;
        }
    }
    return false;
}

bool Kombinasi::isFourAKind(){
    vector<DeckCard> tempArr = arr;
    for(int i = 0; i < tempArr.size() ; i++){
        int temp_num = tempArr[i].getNum();
        vector<DeckCard> temp;
        temp.push_back(tempArr[i]);
        int count_same = 1;

        for (int j = i+1; j < tempArr.size(); j++){
            if(temp_num == tempArr[j].getNum()){
                count_same++;
                temp.push_back(tempArr[j]);
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

bool Kombinasi::isTableCardFourAKind(){
    auto first = arr.begin() + 2;
    auto last = arr.end() - 1;
    vector<DeckCard> tempArr(first, last);
    for(int i = 0; i < tempArr.size() ; i++){
        int temp_num = tempArr[i].getNum();
        vector<DeckCard> temp;
        temp.push_back(tempArr[i]);
        int count_same = 1;

        for (int j = i+1; j < tempArr.size(); j++){
            if(temp_num == tempArr[j].getNum()){
                count_same++;
                temp.push_back(tempArr[j]);
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
    vector<DeckCard> tempArr = arr;
    bool straight = false;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>3; i--)
    {
        if (tempArr[i].getNum()-tempArr[i-4].getNum()==4)
        {
            int temp = tempArr[i-4].getNum()-1;
            for(int j = i-4; j<i+1; j++)
            {
                if ((tempArr[j].getNum()-temp)==1)
                {
                    temp = tempArr[j].getNum();
                    this->arrStraight.push_back(tempArr[j]);
                    straight = true;
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

bool Kombinasi::isTableCardStraight(){
    auto first = arr.begin() + 2;
    auto last = arr.end() - 1;
    vector<DeckCard> tempArr(first, last);
    bool straight = false;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>3; i--)
    {
        if (tempArr[i].getNum()-tempArr[i-4].getNum()==4)
        {
            int temp = tempArr[i-4].getNum()-1;
            for(int j = i-4; j<i+1; j++)
            {
                if ((tempArr[j].getNum()-temp)==1)
                {
                    temp = tempArr[j].getNum();
                    this->arrStraight.push_back(tempArr[j]);
                    straight = true;
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
    vector<DeckCard> tempArr = arr;
    sort(tempArr.begin(), tempArr.end(), compareWarna);
    for (int i = tempArr.size()-1; i>3; i--)
    {
        if (tempArr[i].getType()==tempArr[i-4].getType())
        {
            for (int j = i-4; j < i+1; j++){
                this->arrFlush.push_back(tempArr[i]);
            }
            return true;
        }
    }
    return false;
}

bool Kombinasi::isTableCardFlush(){
    auto first = arr.begin() + 2;
    auto last = arr.end() - 1;
    vector<DeckCard> tempArr(first, last);
    sort(tempArr.begin(), tempArr.end(), compareWarna);
    for (int i = tempArr.size()-1; i>3; i--)
    {
        if (tempArr[i].getType()==tempArr[i-4].getType())
        {
            for (int j = i-4; j < i+1; j++){
                this->arrFlush.push_back(tempArr[i]);
            }
            return true;
        }
    }
    return false;
}

bool Kombinasi::isStraightFlush(){
    vector<DeckCard> tempArr = arr;
    bool straight = false;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>3; i--)
    {
        if (tempArr[i].getNum()-tempArr[i-4].getNum()==4)
        {
            int tempNum = tempArr[i-4].getNum()-1;
            int tempType = tempArr[i-4].getType();
            for(int j = i-4; j<i+1; j++)
            {
                if (((tempArr[j].getNum()-tempNum)==1)&&(tempArr[j].getType()==tempType))
                {
                    tempNum = tempArr[j].getNum();
                    this->arrStraightFlush.push_back(tempArr[j]);
                    straight = true;
                }
                else
                {
                    this->arrStraightFlush.clear();
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

bool Kombinasi::isTableCardStraightFlush(){
    auto first = arr.begin() + 2;
    auto last = arr.end() - 1;
    vector<DeckCard> tempArr(first, last);
    bool straight = false;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>3; i--)
    {
        if (tempArr[i].getNum()-tempArr[i-4].getNum()==4)
        {
            int tempNum = tempArr[i-4].getNum()-1;
            int tempType = tempArr[i-4].getType();
            for(int j = i-4; j<i+1; j++)
            {
                if (((tempArr[j].getNum()-tempNum)==1)&&(tempArr[j].getType()==tempType))
                {
                    tempNum = tempArr[j].getNum();
                    this->arrStraight.push_back(tempArr[j]);
                    straight = true;
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
    vector<DeckCard> tempArr = arr;
    bool threeKind = false;
    vector<DeckCard> tempThreeKind;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = this->arr.size()-1; i>1; i--)
    {
        if (arr[i]==arr[i-2])
        {
            tempThreeKind.push_back(tempArr[i]);
            tempThreeKind.push_back(tempArr[i-1]);
            tempThreeKind.push_back(tempArr[i-2]);
            threeKind = true;
            break;
        }
    }

    if (threeKind)
    {
        for (int i = 0 ; i < tempArr.size() ; i++)
        {
            for (int j = i+1 ; j < tempArr.size() ; j++)
            {
                if(tempArr[i] == tempArr[j])
                {
                    if (!(tempArr[i]==tempThreeKind[0]) && !(tempArr[i]==tempThreeKind[1]) && !(tempArr[i]==tempThreeKind[2]))
                    {
                        return true;
                    }

                }
            }
        }
    }
    return false;
}

bool Kombinasi::isTableCardFullHouse(){
    auto first = arr.begin() + 2;
    auto last = arr.end() - 1;
    vector<DeckCard> tempArr(first, last);
    bool threeKind = false;
    vector<DeckCard> tempThreeKind;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = this->arr.size()-1; i>1; i--)
    {
        if (tempArr[i]==tempArr[i-2])
        {
            tempThreeKind.push_back(tempArr[i]);
            tempThreeKind.push_back(tempArr[i-1]);
            tempThreeKind.push_back(tempArr[i-2]);
            threeKind = true;
            break;
        }
    }

    if (threeKind)
    {
        for (int i = 0 ; i < tempArr.size() ; i++)
        {
            for (int j = i+1 ; j < tempArr.size() ; j++)
            {
                if(tempArr[i] == tempArr[j])
                {
                    if (!(tempArr[i]==tempThreeKind[0]))
                    {
                        return true;
                    }

                }
            }
        }
    }
    return false;
}