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
                    cout << "Sekarang adalah g  iliran Player " << game->players.getPlayer(i).getName() << endl;
                    DeckCard temp1 = game->tableCards.takeCard();
                    DeckCard temp2 = game->tableCards.takeCard();
                    game->players.addPlayerCard(i, temp1);
                    game->players.addPlayerCard(i, temp2);
                    cout<<"Kamu dapat kartu "<<temp1.getNum()<<" "<<temp1.translateToString()<<endl;
                    cout<<"Kamu dapat kartu "<<temp2.getNum()<<" "<<temp1.translateToString()<<endl;
                    //Mulai aksi player                
                    game->players.getPlayer(i).viewAllCard();
                    cout<<endl;
                    cout<<"Tentukan aksi anda: "<<endl;
                    cout<<"1. Next"<<endl;
                    cout<<"2. Double"<<endl;
                    cout<<"3. Half"<<endl;
                    string aksi;
                    cin>>aksi;
                    //Implementasi poin disini
                    //pake getter dan setter poin yg di game manager
                    if (aksi == "1"){
                        //Implementasi next
                    }
                    else if (aksi == "2"){
                        //Implementasi double
                        game->setPoint(game->point*2);
                        cout << game->players.getPlayer(i).getName() << " melakukan DOUBLE! Poin hadiah naik dari " << game->point/2 << " menjadi " << game->point  << "!" << endl;
                    }
                    else if (aksi == "3"){
                        //Implementasi half
                        game->setPoint(game->point/2);
                        cout << game->players.getPlayer(i).getName() << " melakukan HALF! Poin hadiah turun dari " << game->point*2 << " menjadi " << game->point  << "!" << endl;
                    }else{
                        throw "Input Anda salah, silakan ulangi!\n";
                    }
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
                    cout << "Sekarang adalah giliran Player " << game->players.getPlayer(i).getName() << endl;
                    cout<<"Tentukan aksi anda: "<<endl;
                    cout<<"1. Next"<<endl;
                    cout<<"2. Double"<<endl;
                    cout<<"3. Half"<<endl;
                    string aksi;
                    cin>>aksi;
                    //Implementasi poin disini
                    //pake getter dan setter poin yg di game manager
                    if (aksi == "1"){
                        //Implementasi next
                    }
                    else if (aksi == "2"){
                        //Implementasi double
                        game->setPoint(game->point*2);
                        cout << game->players.getPlayer(i).getName() << " melakukan DOUBLE! Poin hadiah naik dari " << game->point/2 << " menjadi " << game->point  << "!" << endl;
                    }
                    else if (aksi == "3"){
                        //Implementasi half
                        game->setPoint(game->point/2);
                        cout << game->players.getPlayer(i).getName() << " melakukan HALF! Poin hadiah turun dari " << game->point*2 << " menjadi " << game->point  << "!" << endl;
                    }else{
                        throw "Input Anda salah, silakan ulangi!\n";
                    }
                }
                if (round == 6)
                {
                    Kombinasi p1 = Kombinasi(game->players.getPlayer(0).getCard(),game->playCards);
                    Kombinasi p2 = Kombinasi(game->players.getPlayer(1).getCard(),game->playCards);
                    Kombinasi p3 = Kombinasi(game->players.getPlayer(2).getCard(),game->playCards);
                    Kombinasi p4 = Kombinasi(game->players.getPlayer(3).getCard(),game->playCards);
                    Kombinasi p5 = Kombinasi(game->players.getPlayer(4).getCard(),game->playCards);
                    Kombinasi p6 = Kombinasi(game->players.getPlayer(5).getCard(),game->playCards);
                    Kombinasi p7 = Kombinasi(game->players.getPlayer(6).getCard(),game->playCards);
                    double idx;
                    vector<double> temp;
                    temp.push_back(p1.value());
                    temp.push_back(p2.value());
                    temp.push_back(p3.value());
                    temp.push_back(p4.value());
                    temp.push_back(p5.value());
                    temp.push_back(p6.value());
                    temp.push_back(p7.value());

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
                    cout<<"Menambahkan poin pada player "<<idx+1<<endl;
                    cout<<"Sebesar "<<game->point<<endl;
                    long long tempPoin = game->players.getPlayer(idx).getPoint();
                    game->players.setPlayerPoint(idx,game->point + tempPoin);
                }
            }
            round++;

            // Ubah Turn
            game->players.nextTurn();
        }
        catch (const char* e){
            cout << e;
        }
    }
    return 0;
}