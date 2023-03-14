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
    int count = 0;
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
                            if (tempC.getCName()=="StraightFlush")
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
                            else if (tempC.getCName() == "FullHouse")
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
    count = 0;
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
                        if(tempC.getCName() == "FourAKind")
                        {
                            this->isFourAKind = true;
                        }
                        else if (tempC.getCName() == "TwoPair")
                        {
                            this->isTwoPair = true;
                        }
                    }
                    temp.clear();
                }
            }
        }
    }
    count = 0;
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
                    if (tempC.getCName() == "ThreeAKind")
                    {
                        this->isThreeAKind = true;
                    }
                }
                temp.clear();
            }
        }
    }

    // //pair
    count = 0;
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
    count = 0;
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
void ArrOfKombinasi::displaySpecificCombination(string input)
{
    dropComb.clear();
    int num = 0;
    if(input == "StraightFlush")
    {
        for (int i = 0 ; i < arrLima.size() ; i++)
        {
            if (arrLima[i].getCName()=="StraightFlush")
            {
                cout<<num+1<<". ";
                arrLima[i].printKombinasi();
                cout<<endl;
                dropComb.push_back(&arrLima[i]);
                num++;
            }
        }
    }
    else if (input == "Flush")
    {
        for (int i = 0 ; i < arrLima.size() ; i++)
        {
            if (arrLima[i].getCName()=="Flush")
            {
                cout<<num+1<<". ";
                arrLima[i].printKombinasi();
                cout<<endl;
                dropComb.push_back(&arrLima[i]);
                num++;
            }
        }
    }
    else if (input == "Straight")
    {
        for (int i = 0 ; i < arrLima.size() ; i++)
        {
            if (arrLima[i].getCName()=="Straight")
            {
                cout<<num+1<<". ";
                arrLima[i].printKombinasi();
                cout<<endl;
                dropComb.push_back(&arrLima[i]);
                num++;
            }
        }
    }
    else if (input == "FullHouse")
    {
        for (int i = 0 ; i < arrLima.size() ; i++)
        {
            if (arrLima[i].getCName()=="FullHouse")
            {
                cout<<num+1<<". ";
                arrLima[i].printKombinasi();
                cout<<endl;
                dropComb.push_back(&arrLima[i]);
                num++;
            }
        }
    }
    else if (input == "FourAKind")
    {
        for (int i = 0 ; i < arrEmpat.size() ; i++)
        {
            if (arrEmpat[i].getCName()=="FourAKind")
            {
                cout<<num+1<<". ";
                arrEmpat[i].printKombinasi();
                cout<<endl;
                dropComb.push_back(&arrEmpat[i]);
                num++;
            }
        }
    }
    else if (input == "TwoPair")
    {
        for (int i = 0 ; i < arrEmpat.size() ; i++)
        {
            if (arrEmpat[i].getCName()=="TwoPair")
            {
                cout<<num+1<<". ";
                arrEmpat[i].printKombinasi();
                cout<<endl;
                dropComb.push_back(&arrEmpat[i]);
                num++;
            }
        }
    }
    else if (input == "ThreeAKind")
    {
        for (int i = 0 ; i < arrTiga.size() ; i++)
        {
            cout<<num+1<<". ";
            arrTiga[i].printKombinasi();
            cout<<endl;
            dropComb.push_back(&arrTiga[i]);
            num++;
        }
    }
    else if (input == "Pair")
    {
        for (int i = 0 ; i < arrDua.size() ; i++)
        {
            cout<<num+1<<". ";
            arrDua[i].printKombinasi();
            cout<<endl;
            dropComb.push_back(&arrDua[i]);
            num++;
        }
    }
    else if (input == "HighCard")
    {
        for (int i = 0 ; i < arrSatu.size() ; i++)
        {
            cout<<num+1<<". ";
            arrSatu[i].printKombinasi();
            cout<<endl;
            dropComb.push_back(&arrSatu[i]);
            num++;
        }
    }
    else
    {
        cout<<"Masukan tidak benar"<<endl;
    }
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

vector<Kombinasi> ArrOfKombinasi::getCombinationList(int num)
{
    if (num = 1)
    {
        return arrSatu;
    }
    else if (num == 2)
    {
        return arrDua;
    }
    else if (num == 3)
    {
        return arrTiga;
    }
    else if (num == 4)
    {
        return arrEmpat;
    }
    else 
    {
        return arrLima;
    }
}

Kombinasi ArrOfKombinasi::DropCombination(int idx)
{
    return *dropComb[idx];
}

int ArrOfKombinasi::dropCombSize()
{
    return dropComb.size();
}