#include "Kombinasi.hpp"
#include <iostream>
#include <cmath>

using namespace std;

bool compareDouble(double n1, double n2){
    // bandingin 2 angka double, return beda kalo sama, false kalo sama 
    double tolerance = 1e-9;
    if (abs(n1 - n2) < tolerance)
    return false;
    return true;
    
}

Kombinasi::Kombinasi(){}

Kombinasi::Kombinasi(vector<DeckCard> playerCards, vector<DeckCard> tableCards)
{
    this->arr.push_back(playerCards[0]);
    this->arr.push_back(playerCards[1]);
    for(int i = 0 ; i < 5 ; i++)
    {
        this->arr.push_back(tableCards[i]);
    }
}

double Kombinasi::getValue()
{
    return this->val;
}
Kombinasi::~Kombinasi()
{
    arr.clear();
    arrCombination.clear();
    arrTableCardCombination.clear();
}

void Kombinasi::setCards(vector<DeckCard> playerCards, vector<DeckCard> tableCards){
    this->arr.push_back(playerCards[0]);
    this->arr.push_back(playerCards[1]);
    for(int i = 0 ; i < 5 ; i++)
    {
        this->arr.push_back(tableCards[i]);
    }
}

double Kombinasi::tableValue(){
    double val;
    if (isTableCardStraightFlush())
    {
        // cout << "TABLE 1\n";
        val = MAX_FOUR_KIND;
        for (DeckCard i : arrTableCardCombination)
        {
            val += i.value();
        }
        return val;
    }
    else if (isTableCardFourAKind())
    {
        // cout << "TABLE 2\n";
        val = MAX_FULL_HOUSE;
        for (DeckCard i : arrTableCardCombination)
        {
            val += i.value();
        }
        return val;
    }
    else if (isTableCardFullHouse())
    {
        // cout << "TABLE 3\n";
        val = MAX_FLUSH;
        for (DeckCard i : arrTableCardCombination)
        {
            val += i.value();
        }
        return val;
    }
    else if (isTableCardFlush())
    {
        // cout << "TABLE 4\n";
        val = MAX_STRAIGHT;
        for (DeckCard i : arrTableCardCombination)
        {
            val += i.value();
        }
        return val;
    }
    else if (isTableCardStraight())
    {
        // cout << "TABLE 5\n";
        val = MAX_THREE_KIND;
        for (DeckCard i : arrTableCardCombination)
        {
            val += i.value();
        }
        // cout << "----------------\n";
        return val;
    }
    else if (isTableCardThreeOfKind())
    {
        // cout << "TABLE 6\n";
        val = MAX_TWO_PAIR;
        for (DeckCard i : arrTableCardCombination)
        {
            val += i.value();
        }
        return val;
    }
    else if (isTableCardTwoPair())
    {
        // cout << "TABLE 7\n";
        val = MAX_PAIR;
        for (DeckCard i : arrTableCardCombination)
        {
            val += i.value();
        }
        return val;
    }
    else if (isTableCardPair())
    {
        // cout << "TABLE 8\n";
        val = MAX_HIGH_CARD;
        for (DeckCard i : arrTableCardCombination)
        {
            val += i.value();
        }
        return val;
    }
    else
    {
        // cout << "TABLE 9\n";
        val = max_element(arr.begin()+2, arr.end(), compareValue)->value();
        return val;
    }

}
vector<DeckCard> Kombinasi::getCombinationCard()
{
    return this->arrCombination;
}
void Kombinasi::printKombinasi()
{
    cout<<endl;
    cout<<"================================================"<<endl;
    cout<<getCName()<<endl;
    cout<<"------------------------------------------------"<<endl;
    for(int i = 0 ; i < arrCombination.size() ; i++)
    {
        // cout<<"TES"<<endl;
        arrCombination[i].printType();
        cout<<" ";
    }
    cout<<endl;
    cout<<"================================================"<<endl;
}

string Kombinasi::getCName()
{
    return combinationName;
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
    double tableVal = tableValue();
    if (isStraightFlush())
    {
        val = MAX_FOUR_KIND;
        for (DeckCard i : arrCombination)
        {
            val += i.value();
        }
        if (compareDouble(val, tableVal))
        {
            // cout << "Straight Flush\n";
            return val;
        }
        else
        {
            if (isFourAKind())
            {
                val = MAX_FULL_HOUSE;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Four Kind\n";
                return val;
            }
            else if (isFullHouse())
            {
                val = MAX_FLUSH;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Full House\n";
                return val;
            }
            else if (isThreeOfKind())
            {
                val = MAX_TWO_PAIR;
                for (auto i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Three Kind\n";
                return val;
            }
            else if (isTwoPair())
            {
                val = MAX_PAIR;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Two Pair\n";
                return val;
            }
            else if (isPair())
            {
                val = MAX_HIGH_CARD;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Pair\n";
                return val;
            }
            else
            {
                // cout << "High Card\n";
                val = max_element(arr.begin(), arr.end(), compareValue)->value();
                return val;
            }
        }
    }
    else if (isFourAKind())
    {      
        val = MAX_FULL_HOUSE;
        for (DeckCard i : arrCombination)
        {
            val += i.value();
        }
        if (compareDouble(val, tableVal))
        {
            // cout << "Four Kind\n";
            return val;
        }
        else
        {
            if (isFullHouse())
            {
                val = MAX_FLUSH;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Full House\n";
                return val;
            }
            else if (isFlush())
            {
                val = MAX_STRAIGHT;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Flush2\n";
                return val;
            }
            else if (isStraight())
            {
                val = MAX_THREE_KIND;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Straight2\n";
                return val;
            }
            else if (isTwoPair())
            {
                val = MAX_PAIR;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Two Pair\n";
                return val;
            }
            else
            {
                // cout << "High Card\n";
                val = max_element(arr.begin(), arr.end(), compareValue)->value();
                return val;
            }
        }
    }
    else if (isFullHouse())
    {
        val = MAX_FLUSH;
        for (DeckCard i : arrCombination)
        {
            val += i.value();
        }
        if (compareDouble(val, tableVal))
        {
            // cout << "Full House" << endl;
            return val;
        }
        else
        {
            if (isFlush())
            {
                val = MAX_STRAIGHT;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Flush3\n";
                return val;
            }
            else if (isStraight())
            {
                val = MAX_THREE_KIND;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Straight3\n";
                return val;
            }
            else if (isTwoPair())
            {
                val = MAX_PAIR;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Two Pair\n";
                return val;
            }
            else
            {
                // cout << "High Card\n";
                val = max_element(arr.begin(), arr.end(), compareValue)->value();
                return val;
            }
        }
    }
    else if (isFlush())
    {
        val = MAX_STRAIGHT;
        for (DeckCard i : arrCombination)
        {
            val += i.value();
        }
        // cout << MAX_STRAIGHT << endl;
        // cout << val << " - " << tableVal << endl;
        if (compareDouble(val, tableVal))
        {
            // cout << "Flush\n";
            return val;
        }
        else
        {
            if (isStraight())
            {
                val = MAX_THREE_KIND;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Straight4\n";
                return val;
            }
            else if (isThreeOfKind())
            {
                val = MAX_TWO_PAIR;
                for (auto i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Three Kind\n";
                return val;
            }
            else if (isTwoPair())
            {
                val = MAX_PAIR;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Two Pair\n";
                return val;
            }
            else if (isPair())
            {
                val = MAX_HIGH_CARD;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Pair\n";
                return val;
            }
            else
            {
                // cout << "High Card\n";
                val = max_element(arr.begin(), arr.end(), compareValue)->value();
                return val;
            }
        }
    }
    else if (isStraight())
    {
        val = MAX_THREE_KIND;
        for (DeckCard i : arrCombination)
        {
            // i.printInfo();
            val += i.value();
        }
        if (compareDouble(val, tableVal))
        {
            // cout << "Straight5\n";
            return val;
        }
        else
        {
            if (isThreeOfKind())
            {
                val = MAX_TWO_PAIR;
                for (auto i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Three Kind\n";
                return val;
            }
            else if (isTwoPair())
            {
                val = MAX_PAIR;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Two Pair\n";
                return val;
            }
            else if (isPair())
            {
                val = MAX_HIGH_CARD;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Pair\n";
                return val;
            }
            else
            {
                // cout << "High Card\n";
                val = max_element(arr.begin(), arr.end(), compareValue)->value();
                return val;
            }
        }
    }
    else if (isThreeOfKind())
    {
        val = MAX_TWO_PAIR;
        for (auto i : arrCombination)
        {
            val += i.value();
        }
        if (compareDouble(val, tableVal))
        {
            // cout << "Three Kind\n";
            return val;
        }
        else
        {
            if (isTwoPair())
            {
                val = MAX_PAIR;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Two Pair\n";
                return val;
            }
            else if (isPair())
            {
                val = MAX_HIGH_CARD;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Pair\n";
                return val;
            }
            else
            {
                // cout << "High Card\n";
                val = max_element(arr.begin(), arr.end(), compareValue)->value();
                return val;
            }
        }
    }
    else if (isTwoPair())
    {
        val = MAX_PAIR;
        for (DeckCard i : arrCombination)
        {
            val += i.value();
        }
        if (compareDouble(val, tableVal))
        {
            // cout << "Two Pair\n";
            return val;
        }
        else
        {
            if (isPair())
            {
                val = MAX_HIGH_CARD;
                for (DeckCard i : arrCombination)
                {
                    val += i.value();
                }
                // cout << "Pair\n";
                return val;
            }
            else
            {
                // cout << "High Card\n";
                val = max_element(arr.begin(), arr.end(), compareValue)->value();
                return val;
            }
        }
    }
    else if (isPair())
    {
        val = MAX_HIGH_CARD;
        for (DeckCard i : arrCombination)
        {
            val += i.value();
        }
        if (compareDouble(val, tableVal))
        {
            // cout << "Pair\n";
            return val;
        }
        else
        {
            // cout << "High Card\n";
            return max_element(arr.begin(), arr.end(), compareValue)->value();   
        }
    }
    else
    {
        val = max_element(arr.begin(), arr.end(), compareValue)->value();
        // cout << "High Card\n";
        if (compareDouble(val, tableVal))
        {
            return val;
        }   
        else
        {
            return max_element(arr.begin(), arr.begin()+1, compareValue)->value();
        }
    }
}

bool Kombinasi::operator<(Kombinasi& other){
    return this->value() < other.value();
}

bool Kombinasi::operator>(Kombinasi& other){
    return this->value() > other.value();
}

bool Kombinasi::operator==(const Kombinasi& other) const {
    return (this->arr == other.arr) && (this->arrCombination == other.arrCombination) && (this->arrTableCardCombination == other.arrTableCardCombination);
}

Kombinasi& Kombinasi::operator=(Kombinasi& other){
    this->arr = other.arr;
    this->arrCombination = other.arrCombination;
    this->arrTableCardCombination = other.arrTableCardCombination;
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
        // cout<<MAX_FOUR_KIND<<endl;
        return "Straight Flush";
    }
    else if (isFourAKind())
    {
        // cout<<MAX_FULL_HOUSE<<endl;
        return "Four a kind";
    }
    else if (isFullHouse())
    {
        // cout<<MAX_FLUSH<<endl;
        return "Full House";
    }
    else if (isFlush())
    {
        // cout<<MAX_STRAIGHT<<endl;
        return "Flush";
    }
    else if (isStraight())
    {
        // cout<<MAX_THREE_KIND<<endl;
        return "Straight";
    }
    else if (isThreeOfKind())
    {
        // cout<<MAX_TWO_PAIR<<endl;
        return "Three of kind";
    }
    else if (isTwoPair())
    {
        // cout<<MAX_PAIR<<endl;
        return "Two Pair";
    }
    else if (isPair())
    {
        // cout<<MAX_HIGH_CARD<<endl;
        return "Pair";
    }
    else
    {
        // cout<<'0'<<endl;
        return "High Card";
    }
}
bool Kombinasi::isPair()
{   
    arrCombination.clear();
    vector<DeckCard> tempArr = arr;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    int tempAngka = 0;
    if (isTableCardPair())
    {
        tempAngka = arrTableCardCombination[0].getNum();
        arrTableCardCombination.clear();
    }
    for (int i = tempArr.size()-1; i>0; i--)
    {
        if((tempArr[i]==tempArr[i-1]) && (tempArr[i].getNum() != tempAngka))
        {
            arrCombination.push_back(tempArr[i]);
            arrCombination.push_back(tempArr[i-1]);
            this->combinationName = "Pair";
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
    //             arrCombination.push_back(arr[i]);
    //             arrCombination.push_back(arr[j]);
    //             return true;
    //         }
    //     }
    // }
    // return false;
}

bool Kombinasi::isTableCardPair()
{   
    arrTableCardCombination.clear();
    auto first = arr.begin() + 2;
    auto last = arr.end();
    vector<DeckCard> tempArr(first, last);
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>0; i--)
    {
        if(tempArr[i]==tempArr[i-1])
        {
            arrTableCardCombination.push_back(tempArr[i]);
            arrTableCardCombination.push_back(tempArr[i-1]);
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
    //             arrCombination.push_back(arr[i]);
    //             arrCombination.push_back(arr[j]);
    //             return true;
    //         }
    //     }
    // }
    // return false;
}

bool Kombinasi::isTwoPair()
{   
    arrCombination.clear();
    vector<DeckCard> tempArr = arr;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    int tempAngka1 = 0;
    int tempAngka2 = 0;
    if (isTableCardTwoPair())
    {
        tempAngka1 = arrTableCardCombination[0].getNum();
        tempAngka2 = arrTableCardCombination[2].getNum();
        arrTableCardCombination.clear();
    }
    for (int i = tempArr.size()-1; i>0; i--)
    {
        if(tempArr[i]==tempArr[i-1])
        {
            for (int j = i-1; j>0; j--)
            {
                if (!(tempArr[j]==tempArr[i]) && (tempArr[j]==tempArr[j-1]) && (tempArr[i].getNum() != tempAngka2) && (tempArr[j].getNum() != tempAngka1))
                {
                    arrCombination.push_back(tempArr[i]);
                    arrCombination.push_back(tempArr[i-1]);
                    arrCombination.push_back(tempArr[j]);
                    arrCombination.push_back(tempArr[j-1]);
                    this->combinationName = "Two Pair";
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
    //                 arrCombination.push_back(temp[i]);
    //             }
    //             return true;
    //         }
    //     }
    // }
    // return false;
}

bool Kombinasi::isTableCardTwoPair()
{   
    arrTableCardCombination.clear();
    auto first = arr.begin() + 2;
    auto last = arr.end();
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
                    arrTableCardCombination.push_back(tempArr[i]);
                    arrTableCardCombination.push_back(tempArr[i-1]);
                    arrTableCardCombination.push_back(tempArr[j]);
                    arrTableCardCombination.push_back(tempArr[j-1]);
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
    //                 arrCombination.push_back(temp[i]);
    //             }
    //             return true;
    //         }
    //     }
    // }
    // return false;
}

bool Kombinasi::isThreeOfKind(){
    arrCombination.clear();
    bool threeOfKind = false;
    vector<DeckCard> tempArr = arr;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    int tempAngka = 0;
    if (isTableCardThreeOfKind())
    {
        tempAngka = arrTableCardCombination[0].getNum();
        arrTableCardCombination.clear();
    }
    for (int i = tempArr.size()-1; i>1; i--)
    {
        if (tempArr[i]==tempArr[i-2] && tempArr[i].getNum() != tempAngka)  //tambahin syarat ga sama kaya di array arrtableCard
                                       //tambahin buat semua yang belum ada if(isTableCard....) kecuali FourAKind
        {
            arrCombination.push_back(tempArr[i]);
            arrCombination.push_back(tempArr[i-1]);
            arrCombination.push_back(tempArr[i-2]);
            threeOfKind = true;
            break;
        }
    }
    if (threeOfKind)
    this->combinationName = "Three of a Kind";
    return threeOfKind;
}

bool Kombinasi::isTableCardThreeOfKind(){
    arrTableCardCombination.clear();
    auto first = arr.begin() + 2;
    auto last = arr.end();
    vector<DeckCard> tempArr(first, last);
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>1; i--)
    {
        if (tempArr[i]==tempArr[i-2])
        {
            arrTableCardCombination.push_back(tempArr[i]);
            arrTableCardCombination.push_back(tempArr[i-1]);
            arrTableCardCombination.push_back(tempArr[i-2]);
            return true;
        }
    }
    return false;
}

bool Kombinasi::isFourAKind(){
    arrCombination.clear();
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
        }
        if(count_same == 4)
        {
            for(int k = 0; k < 4 ; k++){
                arrCombination.push_back(temp[k]);
            }
            this->combinationName = "Four of a Kind";
            return true;
        }
        else
        {
            temp.clear();
            count_same = 0;
        }
    }

    return false;

}

bool Kombinasi::isTableCardFourAKind(){
    arrTableCardCombination.clear();
    auto first = arr.begin() + 2;
    auto last = arr.end();
    vector<DeckCard> tempArr(first, last);
    for(int i = 0; i < tempArr.size() ; i++){
        int temp_num = tempArr[i].getNum();
        vector<DeckCard> temp;
        temp.push_back(tempArr[i]);
        int count_same = 1;
        for (int j = i+1; j < tempArr.size(); j++){
            if(temp_num == tempArr[j].getNum()){
                count_same++;
            }
            if(count_same == 4){
                for(int k = 0; k < 4 ; k++){
                    arrTableCardCombination.push_back(temp[k]);
                }
                return true;
            }
        }
        if(count_same != 4){
            count_same = 0;
        }
    }

    return false;

}



bool Kombinasi::isStraight(){
    arrCombination.clear();
    vector<DeckCard> tempArr = arr;
    vector<int> arrAngka;
    int maxAngkaTable = 0;
    int minAngkaTable = 0;
    int maxAngkaPlayer = 0;
    if (isTableCardStraight())
    {
        arrTableCardCombination.clear();
        maxAngkaTable = max_element(tempArr.begin()+2, tempArr.end(), compareValue)->getNum();
        minAngkaTable = min_element(tempArr.begin()+2, tempArr.end(), compareValue)->getNum();
        maxAngkaPlayer = max_element(tempArr.begin(), tempArr.begin()+2, compareValue)->getNum();
    }
    for(int i = 0; i < tempArr.size(); i++)
    {
        arrAngka.push_back(tempArr[i].getNum());
    }
    for (int i = 0; i < tempArr.size(); i++)
    {
        int tempAngka = tempArr[i].getNum();
        int count = 0;
        for (int j = tempAngka; j < tempAngka+5; j++)
        {
            if ((j==maxAngkaTable && maxAngkaTable>maxAngkaPlayer) || (j==minAngkaTable && maxAngkaTable<maxAngkaPlayer))
            {
                continue;
            }
            auto itr = find(arrAngka.begin(), arrAngka.end(), j);
            while (itr !=arrAngka.end())
            {

                this->arrCombination.push_back(tempArr[itr-arrAngka.begin()]);
                count++;
                break;
                itr = find(itr+1, arrAngka.end(), j);
            }
        }
        if (count==5)
        {
            this->combinationName = "Straight";
            return true;
        }
        arrCombination.clear();

    }
    return false;
}

bool Kombinasi::isTableCardStraight(){
    arrTableCardCombination.clear();
    auto first = arr.begin() + 2;
    auto last = arr.end();
    vector<DeckCard> tempArr(first, last);
    vector<int> arrAngka;
    bool straight = false;

    for(int i = 0; i < tempArr.size(); i++)
    {
        arrAngka.push_back(tempArr[i].getNum());
    }
    for (int i = 0; i < tempArr.size(); i++)
    {
        int tempAngka = tempArr[i].getNum();
        for (int j = tempAngka; j < tempAngka+5; j++)
        {
            int val = j;
            auto itr = find(arrAngka.begin(), arrAngka.end(), val); 
            
            if (itr != arrAngka.end())
            {   
                this->arrTableCardCombination.push_back(tempArr[itr-arrAngka.begin()]);
                straight = true;
            }
            else
            {
                this->arrTableCardCombination.clear();
                straight = false;
                break;
            }
        }
        if (straight)
        {
            return straight;
        }
    }
    return straight;
}

bool Kombinasi::isFlush(){
    
    arrCombination.clear();
    bool flush = false;
    vector<DeckCard> tempArr = arr;
    vector<DeckCard> tempPlayerCard(arr.begin(), arr.begin()+2);
    sort(tempArr.begin(), tempArr.end(), compareWarna);
    sort(tempPlayerCard.begin(), tempPlayerCard.end(), compareAngka);
    for (int i = tempArr.size()-1; i>3; i--)
    {
        if (tempArr[i].getType()==tempArr[i-4].getType())
        {
            for (int j = i; j > i-5; j--){
                this->arrCombination.push_back(tempArr[j]);
            }
            flush = true;
            break;
        }
    }
    if (isTableCardFlush())
    {
        arrTableCardCombination.clear();
        for (int i = tempPlayerCard.size()-1; i>-1; i--)
        {
            if (tempPlayerCard[i].getType() == arrCombination[0].getType())
            {
                arrCombination[0] = tempPlayerCard[i];
                this->combinationName = "Flush";
                return true;
            }
        }
        return false;
    }
    if (flush)
    this->combinationName = "Flush";
    return flush;
}

bool Kombinasi::isTableCardFlush(){
    arrTableCardCombination.clear();
    auto first = arr.begin() + 2;
    auto last = arr.end();
    vector<DeckCard> tempArr(first, last);
    sort(tempArr.begin(), tempArr.end(), compareWarna);
    for (int i = tempArr.size()-1; i>3; i--)
    {
        if (tempArr[i].getType()==tempArr[i-4].getType())
        {
            for (int j = i-4; j < i+1; j++){
                this->arrTableCardCombination.push_back(tempArr[j]);
            }
            return true;
        }
    }
    return false;
}

bool Kombinasi::isStraightFlush(){
    arrCombination.clear();
    vector<DeckCard> tempArr = arr;
    vector<int> arrAngka;
    int maxAngkaTable = 0;
    int minAngkaTable = 0;
    int maxAngkaPlayer = 0;
    if (isTableCardStraightFlush())
    {
        arrTableCardCombination.clear();
        maxAngkaTable = max_element(tempArr.begin()+2, tempArr.end(), compareValue)->getNum();
        minAngkaTable = min_element(tempArr.begin()+2, tempArr.end(), compareValue)->getNum();
        maxAngkaPlayer = max_element(tempArr.begin(), tempArr.begin()+2, compareValue)->getNum();

    }
    for(int i = 0; i < tempArr.size(); i++)
    {
        arrAngka.push_back(tempArr[i].getNum());
    }
    for (int i = 0; i < tempArr.size(); i++)
    {
        int tempAngka = tempArr[i].getNum();
        int tempWarna = tempArr[i].getType();
        
        int count = 0;
        for (int j = tempAngka; j < tempAngka+5; j++)
        {
            if ((j==maxAngkaTable && maxAngkaTable>maxAngkaPlayer) || (j==minAngkaTable && maxAngkaTable<maxAngkaPlayer))
            {
                continue;
            }
            auto itr = find(arrAngka.begin(), arrAngka.end(), j);
            while (itr !=arrAngka.end())
            {
                if (tempArr[itr-arrAngka.begin()].getType() == tempWarna)
                {
                    this->arrCombination.push_back(tempArr[itr-arrAngka.begin()]);
                    count++;
                    break;
                }
                itr = find(itr+1, arrAngka.end(), j);
            }
        }
        if (count==5)
        {
            this->combinationName = "Straight Flush";
            return true;
        }

    }
    return false;
}

bool Kombinasi::isTableCardStraightFlush(){
    arrTableCardCombination.clear();
    auto first = arr.begin() + 2;
    auto last = arr.end();
    vector<DeckCard> tempArr(first, last);
    vector<int> arrAngka;
    bool straight = false;

    for(int i = 0; i < tempArr.size(); i++)
    {
        arrAngka.push_back(tempArr[i].getNum());
    }
    for (int i = 0; i < tempArr.size(); i++)
    {
        int tempAngka = tempArr[i].getNum();
        int tempWarna = tempArr[i].getType();
        for (int j = tempAngka; j < tempAngka+5; j++)
        {
            int val = j;
            auto itr = find(arrAngka.begin(), arrAngka.end(), val); 
            
            if (itr != arrAngka.end() && tempArr[itr-arrAngka.begin()].getType() == tempWarna)
            {   
                this->arrTableCardCombination.push_back(tempArr[itr-arrAngka.begin()]);
                straight = true;
            }
            else
            {
                this->arrTableCardCombination.clear();
                straight = false;
                break;
            }
        }
        if (straight)
        {
            return straight;
        }
    }
    return straight;
}

bool Kombinasi::isFullHouse(){
    arrCombination.clear();
    vector<DeckCard> tempArr = arr;
    vector<int> arrAngka;
    vector<int> arrAngkaFullHouse;
    bool threeKind = false;
    bool fullHouse = false;
    vector<DeckCard> tempThreeKind;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for(int i = 0; i < tempArr.size(); i++)
    {
        arrAngka.push_back(tempArr[i].getNum());
    }
    for (int i = tempArr.size()-1; i>1; i--)
    {
        if (tempArr[i]==tempArr[i-2])
        {
            tempThreeKind.push_back(tempArr[i-2]);
            tempThreeKind.push_back(tempArr[i]);
            tempThreeKind.push_back(tempArr[i-1]);
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
                if((tempArr[i] == tempArr[j]) && !(tempArr[i]==tempThreeKind[0]))
                {
                    this->arrCombination.push_back(tempArr[i]);
                    this->arrCombination.push_back(tempArr[j]);
                    arrAngkaFullHouse.push_back(tempArr[i].getNum());
                    arrAngkaFullHouse.push_back(tempArr[j].getNum());
                    for (auto card : tempThreeKind)
                    {
                        this->arrCombination.push_back(card);
                        arrAngkaFullHouse.push_back(card.getNum());
                    }
                    fullHouse = true;
                    break;
                }
            }
            if (fullHouse)
            break;
        }
    }
    if (isTableCardFullHouse())
    {
        arrTableCardCombination.clear();
        auto itr1 = find(arrAngka.begin(), arrAngka.end(), arr[0].getNum());
        auto itr2 = find(arrAngka.begin(), arrAngka.end(), arr[1].getNum());
        if ((arr[0].getNum() > arr[1].getNum()) && (itr1 != arrAngkaFullHouse.end()))
        {
            this->arrCombination[itr1-arrAngkaFullHouse.begin()] = arr[0];
        }
        else if (itr2 != arrAngkaFullHouse.end())
        {
            this->arrCombination[itr2-arrAngkaFullHouse.begin()+1] = arr[1];
        }
        else if (itr1 != arrAngkaFullHouse.end())
        {
            this->arrCombination[itr1-arrAngkaFullHouse.begin()] = arr[0];
        }
        else
        {
            fullHouse = false;
            arrCombination.clear();
        }
    }
    if (fullHouse)
    this->combinationName = "Full House";
    return fullHouse;
}

bool Kombinasi::isTableCardFullHouse(){
    arrTableCardCombination.clear();
    auto first = arr.begin() + 2;
    auto last = arr.end();
    vector<DeckCard> tempArr(first, last);
    bool threeKind = false;
    vector<DeckCard> tempThreeKind;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>1; i--)
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
                        this->arrTableCardCombination.push_back(tempArr[i]);
                        this->arrTableCardCombination.push_back(tempArr[j]);
                        for (auto card : tempThreeKind)
                        {
                            this->arrTableCardCombination.push_back(card);
                        }
                        return true;
                    }
                }
            }
        }
    }
    return false;
}