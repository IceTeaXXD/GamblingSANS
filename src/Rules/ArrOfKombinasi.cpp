#include "ArrOfKombinasi.hpp"
using namespace std;

ArrOfKombinasi::ArrOfKombinasi(vector<DeckCard> arrInput)
{
    //Straight Flush,Flush, Straight, Two Pair, 
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
                        Kombinasi* tempC = new Kombinasi(temp);
                        // if (tempC->value()>=tempC->getConst(5) && tempC->value()<=tempC->getConst(7) || tempC->value()>=tempC->getConst(9))
                        // {
                        //     arr.push_back(temp);
                        //     cout<<"1"<<endl;
                        // }
                        temp.clear();
                    }
                }
            }
        }
    }

    //Four a kind, 2 pair
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
                    Kombinasi* tempC = new Kombinasi(temp);
                    // if (tempC->value()>=tempC->getConst(8) && tempC->value()<=tempC->getConst(9) || tempC->value()>=tempC->getConst(3) && tempC->value()<=tempC->getConst(4))
                    // {
                    //     arr.push_back(temp);
                    //     cout<<"2"<<endl;
                    // }
                    temp.clear();
                }
            }
        }
    }

    //three of kind
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
                Kombinasi* tempC = new Kombinasi(temp);
                // if (tempC->value()>=tempC->getConst(4) && tempC->value()<=tempC->getConst(5))
                // {
                //     arr.push_back(temp);
                //     cout<<"3"<<endl;
                // }
                temp.clear();
            }
        }
    }

    //pair
    for (int l = 0 ; l<arrInput.size()-1 ; l++)
    {
        for (int m = l+1; m<arrInput.size() ; m++)
        {
            vector<DeckCard> temp;
            temp.push_back(arrInput[l]);
            temp.push_back(arrInput[m]);
            Kombinasi* tempC = new Kombinasi(temp);
            // if (tempC->value()>=tempC->getConst(2) && tempC->value()<=tempC->getConst(3))
            // {
            //     arr.push_back(temp);
            //     cout<<"4"<<endl;
            // }
            temp.clear();
        }
    }

    //HighCard
    for (int m = 0; m<1 ; m++)
    {
        vector<DeckCard> temp;
        temp.push_back(arrInput[m]);
        Kombinasi* tempC = new Kombinasi(temp);
        //value ini ada yang salah
        double tempValue = tempC->value();
        // if (tempValue>=tempC->getConst(1) && tempValue<=tempC->getConst(2))
        // {
        //     arr.push_back(temp);
        //     cout<<"5"<<endl;
        // }
        temp.clear();
        tempC->~Kombinasi();
    }
}
ArrOfKombinasi::ArrOfKombinasi(){}
ArrOfKombinasi::~ArrOfKombinasi()
{
    arr.clear();
}

// Kombinasi& ArrOfKombinasi::getKombinasi(int idx)
// {
//     //Implementasi hapus kombinasi ke idx
// }

void ArrOfKombinasi::addKombinasi(Kombinasi& k)
{
    arr.push_back(k);
}

void ArrOfKombinasi::displayKombinasi()
{
    for (int i = 0 ; i < arr.size() ; i++)
    {
        arr[i].printKombinasi();
    }
}