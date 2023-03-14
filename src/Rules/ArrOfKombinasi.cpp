#include "ArrOfKombinasi.hpp"
using namespace std;

ArrOfKombinasi::ArrOfKombinasi(vector<DeckCard> arrInput)
{
    //Straight Flush,Flush, Straight, Two Pair,
    this->isStraightFlush = false;
    this->isFourAKind = false;
    this->isFullHouse = false;
    this->isFlush = false;
    this->isStraight = false;
    this->isThreeAKind = false;
    this->isTwoPair = false;
    this->isPair = false;
    this->isHighCard = false;
    for(int i = 0; i< arrInput.size()-4 ; i ++)
    {
        for (int j = i+1 ; j< arrInput.size()-3 ; j++)
        {
            for (int k = j+1; k<arrInput.size()-2 ; k++)
            {
                for (int l = k+1 ; l<arrInput.size()-1 ; l++)
                {
                    for (int m = l+1; m<arrInput.size() ; m++)
                    {
                        vector<DeckCard> temp;
                        temp.push_back(arrInput[i]);
                        temp.push_back(arrInput[j]);
                        temp.push_back(arrInput[k]);
                        temp.push_back(arrInput[l]);
                        temp.push_back(arrInput[m]);
                        KombinasiCapsa tempC = KombinasiCapsa(temp,5);
                        if (tempC.getValue()!=0)
                        {
                            arrLima.push_back(tempC);
                            if (tempC.getCName()=="Straight Flush")
                            {
                                this->isStraightFlush = true;
                            }
                            else if (tempC.getCName()=="Flush")
                            {
                                this->isFlush = true;
                            }
                            else if (tempC.getCName() == "Straight")
                            {
                                this->isStraight = true;
                            }
                            else if (tempC.getCName() == "Full House")
                            {
                                this->isFullHouse = true;
                            }
                        }
                        temp.clear();
                    }
                }
            }
        }
    }

    // Four a kind, 2 pair
    for (int j = 0 ; j< arrInput.size()-3 ; j++)
    {
        for (int k = j+1; k<arrInput.size()-2 ; k++)
        {
            for (int l = k+1 ; l<arrInput.size()-1 ; l++)
            {
                for (int m = l+1; m<arrInput.size() ; m++)
                {
                    vector<DeckCard> temp;
                    temp.push_back(arrInput[j]);
                    temp.push_back(arrInput[k]);
                    temp.push_back(arrInput[l]);
                    temp.push_back(arrInput[m]);
                    KombinasiCapsa tempC = KombinasiCapsa(temp,4);
                    if (tempC.getValue()!=0)
                    {
                        arrEmpat.push_back(tempC);
                        if(tempC.getCName() == "Four of a Kind")
                        {
                            this->isFourAKind = true;
                        }
                        else if (tempC.getCName() == "Two Pair")
                        {
                            this->isTwoPair = true;
                        }
                    }
                    temp.clear();
                }
            }
        }
    }

    // //three of kind
    for (int k = 0 ; k<arrInput.size()-2 ; k++)
    {
        for (int l = k+1 ; l<arrInput.size()-1 ; l++)
        {
            for (int m = l+1; m<arrInput.size() ; m++)
            {
                vector<DeckCard> temp;
                temp.push_back(arrInput[k]);
                temp.push_back(arrInput[l]);
                temp.push_back(arrInput[m]);
                KombinasiCapsa tempC = KombinasiCapsa(temp,3);
                if (tempC.getValue()!=0)
                {
                    arrTiga.push_back(tempC);
                    if (tempC.getCName() == "Three of a Kind")
                    {
                        this->isThreeAKind = true;
                    }
                }
                temp.clear();
            }
        }
    }

    // //pair
    for (int l = 0 ; l<arrInput.size()-1 ; l++)
    {
        for (int m = l+1; m<arrInput.size() ; m++)
        {
            vector<DeckCard> temp;
            temp.push_back(arrInput[l]);
            temp.push_back(arrInput[m]);
            KombinasiCapsa tempC =  KombinasiCapsa(temp,2);
            if (tempC.getValue()!=0)
            {
                arrDua.push_back(tempC);
                if (tempC.getCName() == "Pair")
                {
                    this->isPair = true;
                }
            }
            temp.clear();
        }
    }

    // //HighCard
    for (int m = 0; m<arrInput.size() ; m++)
    {
        vector<DeckCard> temp;
        temp.push_back(arrInput[m]);
        KombinasiCapsa tempC = KombinasiCapsa(temp,1);
        arrSatu.push_back(tempC);
        isHighCard = true;
        temp.clear();
    }
}
ArrOfKombinasi::ArrOfKombinasi(){}
ArrOfKombinasi::~ArrOfKombinasi()
{
    arrLima.clear();
    arrEmpat.clear();
    arrTiga.clear();
    arrDua.clear();
    arrSatu.clear();
}

// Kombinasi& ArrOfKombinasi::getKombinasi(int idx)
// {
//     //Implementasi hapus kombinasi ke idx
// }

void ArrOfKombinasi::addKombinasi(Kombinasi& k)
{
    // arr.push_back(k);
}
void ArrOfKombinasi::displayCombinationList()
{
    cout<<"KOMBINASI YANG ANDA PUNYA : "<<endl;
    if (isStraightFlush)
    {
        cout<<"Straight Flush"<<endl;
    }
    if (isFourAKind)
    {
        cout<<"Four A Kind"<<endl;
    }
    if (isFullHouse)
    {
        cout<<"Full House"<<endl;
    }
    if (isFlush)
    {
        cout<<"Flush"<<endl;
    }
    if (isThreeAKind)
    {
        cout<<"Three A Kind"<<endl;
    }
    if(isTwoPair)
    {
        cout<<"Two Pair"<<endl;
    }
    if(isPair)
    {
        cout<<"Pair"<<endl;
    }
    cout<<"High Card"<<endl;
}
void ArrOfKombinasi::displayKombinasi()
{
    for (int i = 0 ; i < arrLima.size() ; i++)
    {
        arrLima[i].printKombinasi();
    }
    for (int i = 0 ; i < arrEmpat.size() ; i++)
    {
        arrEmpat[i].printKombinasi();
    }
    for (int i = 0 ; i < arrTiga.size() ; i++)
    {
        arrTiga[i].printKombinasi();
    }
    for (int i = 0 ; i < arrDua.size() ; i++)
    {
        arrDua[i].printKombinasi();
    }
    for (int i = 0 ; i < arrSatu.size() ; i++)
    {
        arrSatu[i].printKombinasi();
    }
}