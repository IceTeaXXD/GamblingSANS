#include <iostream>
#include "AbilityCard.hpp"

AbilityCard::AbilityCard(bool avail) : Card()
{
    availability = true;
}

bool AbilityCard::isAvailable()
{
    return availability;
}

void AbilityCard::setNotAvailable()
{
    availability = false;
}
Player AbilityCard::getOwner(AbilityCard* a)
{
    return a->owner;
}
void REROLL::use(Card* )
{
    //Buat array dg isi objek kartu dulu baru bisa diimplementasi
    if (isAvailable())
    {
        this->setNotAvailable();
    }
    else
    {}
}

void Quadruple::use()
{
    if (isAvailable())
    {
        this->setNotAvailable();
    }
    else
    {
    }
}
void Abilityless::use()
{
    if (isAvailable())
    {
        //CASENYA KURANG YANG SEMUA KARTU ABILITY SUDAH MATI
        Player owner = getOwner(this);
        string name;
        cout<<owner.getName()<<" akan mematikan kartu ability lawan"<<endl;
        cout<<"Silahkan pilih pemain yang kartu abilitynya ingin dimatikan: "<<endl;
        cin>>name;
        //Kurang bikin fungsi buat cari objek player dg name = "XXX";
        // if (isAvailable())
        // {
            // Player temp = getOwner(other);
            // cout<<"Kartu ability "<< temp.getName() <<" telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia 🙁"<<endl;
        // }
        // other->setNotAvailable();
        this->setNotAvailable();
    }
}

