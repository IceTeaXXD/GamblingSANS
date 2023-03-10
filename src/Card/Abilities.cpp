#include "Abilities.hpp"

REROLL::REROLL(){ this-> type = "rerroll"; }

void REROLL::use(CardCollection<DeckCard>* cardPlayer, CardCollection<DeckCard>* game,  int i)
{
    //Buat array dg isi objek kartu dulu baru bisa diimplementasi
    if (isAvailable())
    {
        this->setNotAvailable();

        /* Kosongkan Kartu terlebih dahulu */
        cardPlayer->clear();

        /* Tambahin Kartu Baru */
        DeckCard temp1 = game->takeCard();
        DeckCard temp2 = game->takeCard();
        game->addCard(temp1);
        game->addCard(temp2);

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

Quadruple::Quadruple(){ this-> type = "quadruple"; }

void Quadruple::use(int* point)
{
    if (isAvailable())
    {
        this->setNotAvailable();

        /* Set point jadi 4 kali */
        *point *= 4;

        /* OUTPUT */
        cout << "Point berubah menjadi " << *point << endl;
        
    }
    else
    {
        cout << "Anda tidak punya kartu ini!" << endl;
    }
}

Quarter::Quarter(){this-> type = "quarter";}

void Quarter::use(int* point){
    if (isAvailable())
    {
        this->setNotAvailable();

        /* Set point jadi 1/4 kali */
        *point /= 4;
        
        /* OUTPUT */
        if(*point >= 0){
            cout << "Point berubah menjadi " << *point << endl;
        }else{
            *point *= 4;
            cout << "Nothing happened" << endl;
        }
    }
    else
    {
        cout << "Anda tidak punya kartu ini!" << endl;
    }
}

ReverseDirection::ReverseDirection(){ type = "reverse"; }

void ReverseDirection::use(ArrOfPlayer* game, int round){
    game->reverseTurn(round);
}

SwapCard::SwapCard(){type = "swap";}

void SwapCard::use(Player* p1, Player* p2){
    DeckCard temp = p1->getCard().getCard(0);
    p1->getCard().getCard(0) = p2->getCard().getCard(0);
    p2->getCard().getCard(0) = temp;
}

Switch::Switch(){type = "switch";}

void Switch::use(Player* p1, Player* p2){
    CardCollection<DeckCard> temp = p1->getCard();
    p1->getCard() = p2->getCard();
    p2->getCard() = temp;
}

Abilityless::Abilityless(){type = "abilityless"; }

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

void AbilityCard::printInfo()
{
    cout<<"ABILITY CARD"<<endl;
}

void REROLL::printInfo()
{
    cout<<"REROLL"<<endl;
}

void Quadruple::printInfo()
{
    cout<<"QUADRUPLE"<<endl;
}

void Quarter::printInfo()
{
    cout<<"QUARTER"<<endl;
}

void ReverseDirection::printInfo()
{
    cout<<"REVERSE DIRECTION"<<endl;
}

void SwapCard::printInfo()
{
    cout<<"SWAP CARD"<<endl;
}

void Switch::printInfo()
{
    cout<<"SWITCH"<<endl;
}

void Abilityless::printInfo()
{
    cout<<"ABILITYLESS"<<endl;
}