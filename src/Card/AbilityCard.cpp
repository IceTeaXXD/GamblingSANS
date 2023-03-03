#include <iostream>
#include "AbilityCard.hpp"
using namespace std;
AbilityCard::AbilityCard()
{
    availability = true;
}
AbilityCard::AbilityCard(bool avail)
{
    availability = avail;
}

bool AbilityCard::isAvailable()
{
    return availability;
}

void AbilityCard::setNotAvailable()
{
    availability = false;
}
// Player AbilityCard::getOwner(AbilityCard* a)
// {
//     return a->owner;
// }
void AbilityCard::use()
{
    cout<<"Menggunakan ability card"<<endl;
}

REROLL::REROLL(){}

void REROLL::use(GameManager* game, int i)
{
    //Buat array dg isi objek kartu dulu baru bisa diimplementasi
    if (isAvailable())
    {
        this->setNotAvailable();

        /* Kosongkan Kartu terlebih dahulu */
        game->players.clearCard(i);

        /* Tambahin Kartu Baru */
        DeckCard temp1 = game->tableCards.takeCard();
        DeckCard temp2 = game->tableCards.takeCard();
        game->players.addPlayerCard(i, temp1);
        game->players.addPlayerCard(i, temp2);

        /* OUTPUT */
        cout<<"RE-ROLLED"<<endl;
        cout<<"Kamu dapat kartu "<<temp1.getNum()<<" "<<temp1.translateToString()<<endl;
        cout<<"Kamu dapat kartu "<<temp2.getNum()<<" "<<temp1.translateToString()<<endl;
    }
    else
    {
        cout << "Anda tidak punya kartu ini!" << endl;
    }
}

Quadruple::Quadruple(){}

void Quadruple::use(int a, GameManager* game)
{
    if (isAvailable())
    {
        this->setNotAvailable();

        /* Set point jadi 4 kali */
        game->setPoint(a*4);

        /* OUTPUT */
        cout << "Point berubah menjadi " << game->point << endl;
        
    }
    else
    {
        cout << "Anda tidak punya kartu ini!" << endl;
    }
}

Quarter::Quarter(){}

void Quarter::use(int i, GameManager* game){
    if (isAvailable())
    {
        this->setNotAvailable();

        /* Set point jadi 4 kali */
        game->setPoint(i/4);
        
        /* OUTPUT */
        cout << "Point berubah menjadi " << game->point << endl;
    }
    else
    {
        cout << "Anda tidak punya kartu ini!" << endl;
    }
}

ReverseDirection::ReverseDirection(){}

void ReverseDirection::use(GameManager* game){
    game->players.reverseTurn();
}

void Abilityless::use()
{
    if (isAvailable())
    {
        //CASENYA KURANG YANG SEMUA KARTU ABILITY SUDAH MATI
        // Player owner = getOwner(this);
        // string name;
        // cout<<owner.getName()<<" akan mematikan kartu ability lawan"<<endl;
        // cout<<"Silahkan pilih pemain yang kartu abilitynya ingin dimatikan: "<<endl;
        // cin>>name;
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

