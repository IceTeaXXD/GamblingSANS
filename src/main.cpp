#include <iostream>
// #include "Card/AbilityCard.hpp"
#include "Card/DeckCard.hpp"
#include "GameManager/GameManager.hpp"
#include "Player/Player.hpp"
#include "Rules/Kombinasi.hpp"

int main()
{
    GameManager* game = new GameManager();
    int round = 1;
    while(true){
        try{
            cout << "ROUND " << round << endl;
            if (round == 1){
                // for each player give 2 cards from table cards
                for (int i = 0 ; i < 7 ; i++){
                    //Implementasi penunjuk player yg main
                    //CONTOH : "Sekarang saatnya Player I"
                    cout << "Sekarang adalah giliran Player " << game->players.getPlayer(0).getName() << endl;
                    DeckCard temp1 = game->tableCards.takeCard();
                    DeckCard temp2 = game->tableCards.takeCard();
                    game->players.addPlayerCard(0, temp1);
                    game->players.addPlayerCard(0, temp2);
                    cout<<"Kamu dapat kartu "<<temp1.getNum()<<" "<<temp1.translateToString()<<endl;
                    cout<<"Kamu dapat kartu "<<temp2.getNum()<<" "<<temp2.translateToString()<<endl;
                    //Mulai aksi player                
                    game->players.getPlayer(0).viewAllCard();
                    cout<<endl;
                    cout<<"Tentukan aksi anda: "<<endl;
                    cout<<"1. Next"<<endl;
                    cout<<"2. Double"<<endl;
                    cout<<"3. Half"<<endl;
                    string aksi;
                    cin>>aksi;
                    //Implementasi poin disini
                    //pake getter dan setter poin yg di game manager
                    if (game->isInputTrue(aksi, "next")){
                        //Implementasi next
                    }
                    else if (game->isInputTrue(aksi, "double")){
                        //Implementasi double
                        game->setPoint(game->point*2);
                        cout << game->players.getPlayer(0).getName() << " melakukan DOUBLE! Poin hadiah naik dari " << game->point/2 << " menjadi " << game->point  << "!" << endl;
                    }
                    else if (game->isInputTrue(aksi, "half")){
                        //Implementasi half
                        game->setPoint(game->point/2);
                        cout << game->players.getPlayer(0).getName() << " melakukan HALF! Poin hadiah turun dari " << game->point*2 << " menjadi " << game->point  << "!" << endl;
                    }else{
                        throw "Input Anda salah, silakan ulangi!\n";
                    }
                    game->players.nextTurn();
                }
                // Give 1 ability card to each player
                /* TODO */
                cout<<"Ronde I telah berakhir"<<endl;
                DeckCard temp = game->tableCards.takeCard();
                game->playCards+temp;
                cout<<"Kartu "<<temp.getNum()<<" "<<temp.translateToString()<<" telah ditambahkan di meja"<<endl;
                cout<<endl;
                game->playCards.displayDeckCard();
            }

            else if(round >= 2 && round <= 6)
            {
                if(round < 6){
                    DeckCard temp = game->tableCards.takeCard();
                    game->playCards+temp;
                    cout<<"Kartu "<<temp.getNum()<<" "<<temp.translateToString()<<" telah ditambahkan di meja"<<endl;
                }
                cout<<endl;
                game->playCards.displayDeckCard();
                //Implementasi penunjuk player yg main
                //CONTOH : "Sekarang saatnya PlayerI"
                //Tambahin juga buat tampilin kartu apa aja yang dimeja + dipunya player
                for (int i = 0 ; i < 7 ; i++){
                    cout << "Sekarang adalah giliran Player " << game->players.getPlayer(0).getName() << endl;
                    cout<<"Tentukan aksi anda: "<<endl;
                    cout<<"1. Next"<<endl;
                    cout<<"2. Double"<<endl;
                    cout<<"3. Half"<<endl;
                    string aksi;
                    cin>>aksi;
                    //Implementasi poin disini
                    //pake getter dan setter poin yg di game manager
                    if (game->isInputTrue(aksi, "next")){
                        //Implementasi next
                    }
                    else if (game->isInputTrue(aksi, "double")){
                        //Implementasi double
                        game->setPoint(game->point*2);
                        cout << game->players.getPlayer(0).getName() << " melakukan DOUBLE! Poin hadiah naik dari " << game->point/2 << " menjadi " << game->point  << "!" << endl;
                    }
                    else if (game->isInputTrue(aksi, "half")){
                        //Implementasi half
                        game->setPoint(game->point/2);
                        cout << game->players.getPlayer(0).getName() << " melakukan HALF! Poin hadiah turun dari " << game->point*2 << " menjadi " << game->point  << "!" << endl;
                    }else{
                        throw "Input Anda salah, silakan ulangi!\n";
                    }
                    game->players.nextTurn();
                }
                if (round == 6)
                {
                    vector<Kombinasi> tempKombinasi;
                    tempKombinasi.push_back(Kombinasi(game->players.getPlayer(0).getCard(),game->playCards));
                    tempKombinasi.push_back(Kombinasi(game->players.getPlayer(1).getCard(),game->playCards));
                    tempKombinasi.push_back(Kombinasi(game->players.getPlayer(2).getCard(),game->playCards));
                    tempKombinasi.push_back(Kombinasi(game->players.getPlayer(3).getCard(),game->playCards));
                    tempKombinasi.push_back(Kombinasi(game->players.getPlayer(4).getCard(),game->playCards));
                    tempKombinasi.push_back(Kombinasi(game->players.getPlayer(5).getCard(),game->playCards));
                    tempKombinasi.push_back(Kombinasi(game->players.getPlayer(6).getCard(),game->playCards));

                    double idx;
                    vector<double> temp;
                    for (int i = 0 ; i < 7 ; i++)
                    {
                        temp.push_back(tempKombinasi[i].value());
                    }

                    cout<<"Nilai Tertinggi yaitu "<<maxVector<double>(temp)<<endl;
                    if (temp.size()>0)
                    {
                        double tempval = temp[0];
                        for (int i = 0 ; i < temp.size() ; i++)
                        {
                            if (temp[i]>tempval)
                            {
                                tempval = temp[i];
                                idx = i;
                            }
                        }
                    }
                    cout<<tempKombinasi[idx].getCombinationName()<<endl;
                    cout<<"Menambahkan poin pada player "<<idx+1<<endl;
                    cout<<"Sebesar "<<game->point<<endl;

                    cout<<"Table Card List"<<endl;
                    game->playCards.displayDeckCard();

                    cout<<"Player Card :"<<endl;
                    for (int i = 0 ; i < 7 ; i++)
                    {
                        cout<<"Player "<<i<<endl;
                        game->players.getPlayer(i).viewAllCard();
                    }
                    long long tempPoin = game->players.getPlayer(idx).getPoint();
                    game->players.setPlayerPoint(idx,game->point + tempPoin);
                }
            }
            round++;
            // Ubah Turn
            if (round > 6)
            {
                break;
            }
            game->players.nextTurn();
        }
        catch (const char* e){
            cout << e;
        }
    }
    return 0;
}