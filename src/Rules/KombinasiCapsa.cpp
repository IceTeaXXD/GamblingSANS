#include "KombinasiCapsa.hpp"

using namespace std;

KombinasiCapsa::KombinasiCapsa(){

}

KombinasiCapsa::KombinasiCapsa(vector<DeckCard> playCards,int n)
{
    for (int i = 0 ; i < playCards.size() ; i++)
    {
        this->arr.push_back(playCards[i]);
    }
    this->arrCombination = playCards;
    double val;
    if (n==5)
    {
        if(isTableCardStraightFlush())
        {
            val = MAX_FOUR_KIND;
            for (DeckCard i : arrTableCardCombination)
            {
                val += i.value();
            }
            this->val = val;
            this->combinationName = "Straight Flush";
        }
        else if (isTableCardFullHouse())
        {
            val = MAX_FLUSH;
            for (DeckCard i : arrTableCardCombination)
            {
                val += i.value();
            }
            this->val = val;
            this->combinationName = "Full House";
        }
        else if (isTableCardFlush())
        {
            val = MAX_STRAIGHT;
            for (DeckCard i : arrTableCardCombination)
            {
                val += i.value();
            }
            this->val = val;
            this->combinationName = "Flush";
        }
        else if(isTableCardStraight())
        {
            val = MAX_THREE_KIND;
            for (DeckCard i : arrTableCardCombination)
            {
                val += i.value();
            }
            this->val = val;
            this->combinationName = "Straight";
        }
        else 
        {
            this->val = 0;
        }
    }
    else if (n==4)
    {
        if (isFourAKind())
        {
            val = MAX_FULL_HOUSE;
            for (DeckCard i : arrTableCardCombination)
            {
                val += i.value();
            }
            this->val = val;
            this->combinationName = "Four A Kind";
        }
        else if (isTwoPair())
        {
            val = MAX_PAIR;
            for (DeckCard i : arrTableCardCombination)
            {
                val += i.value();
            }
            this->val = val;
            this->combinationName = "Two Pair";
        }
        else
        {
            this->val = 0;
        }
    }
    else if (n==3)
    {
        if (isThreeOfKind())
        {
            val = MAX_TWO_PAIR;
            for (DeckCard i : arrTableCardCombination)
            {
                val += i.value();
            }
            this->val = val;
            this->combinationName = "Three a Kind";
        }
        else
        {
            this->val = 0;
        }
    }
    else if (n==2)
    {
        if(isPair())
        {
            val = MAX_HIGH_CARD;
            for (DeckCard i : arrTableCardCombination)
            {
                val += i.value();
            }
            this->val = val;
            this->combinationName = "Pair";
        }
        else
        {
            this->val = 0;
        }
    }
    else
    {
        // cout << "TABLE 9\n";
        val = arr.begin()->value();
        this->val = val;
        this->combinationName = "High Card";
    }
}

KombinasiCapsa::~KombinasiCapsa(){
    
}

double KombinasiCapsa::getConst(int input)
{
    if (input == 1)
    {
        return MAX_HIGH_CARD;
    }
    else if (input==2)
    {
        return MAX_PAIR;
    }
    else if (input == 3)
    {
        return MAX_TWO_PAIR;
    }
    else if (input == 4)
    {
        return MAX_THREE_KIND;
    }
    else if (input == 5)
    {
        return MAX_STRAIGHT;
    }
    else if (input == 6)
    {
        return MAX_FLUSH;
    }
    else if (input==7)
    {
        return MAX_FULL_HOUSE;
    }
    else if(input == 8)
    {
        return MAX_FOUR_KIND;
    }
    else
    {
        return MAX_STRAIGHT_FLUSH;
    }
}

bool KombinasiCapsa::isPair(){
    arrCombination.clear();
    vector<DeckCard> tempArr = arr;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>0; i--)
    {
        if(tempArr[i]==tempArr[i-1])
        {
            arrCombination.push_back(tempArr[i]);
            arrCombination.push_back(tempArr[i-1]);
            return true;
        }
    }
    return false;
}

bool KombinasiCapsa::isTwoPair(){
    arrCombination.clear();
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
                    arrCombination.push_back(tempArr[i]);
                    arrCombination.push_back(tempArr[i-1]);
                    arrCombination.push_back(tempArr[j]);
                    arrCombination.push_back(tempArr[j-1]);
                    return true;
                }
            }
        }
    }
    return false;
}

bool KombinasiCapsa::isThreeOfKind(){
    arrCombination.clear();
    bool threeOfKind = false;
    vector<DeckCard> tempArr = arr;
    sort(tempArr.begin(), tempArr.end(), compareAngka);
    for (int i = tempArr.size()-1; i>1; i--)
    {
        if (tempArr[i]==tempArr[i-2])  //tambahin syarat ga sama kaya di array arrtableCard
                                       //tambahin buat semua yang belum ada if(isTableCard....) kecuali FourAKind
        {
            arrCombination.push_back(tempArr[i]);
            arrCombination.push_back(tempArr[i-1]);
            arrCombination.push_back(tempArr[i-2]);
            threeOfKind = true;
            break;
        }
    }
    return false;
}

bool KombinasiCapsa::isStraight(){
    arrCombination.clear();
    vector<DeckCard> tempArr = arr;
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

bool KombinasiCapsa::isFlush(){
    
    arrCombination.clear();
    bool flush = false;
    vector<DeckCard> tempArr = arr;
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

bool KombinasiCapsa::isFullHouse(){
    arrTableCardCombination.clear();
    vector<DeckCard> tempArr = arr;
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

bool KombinasiCapsa::isStraightFlush(){
    arrTableCardCombination.clear();
    vector<DeckCard> tempArr = arr;
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