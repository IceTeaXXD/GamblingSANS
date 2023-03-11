#include <iostream>
// #include "Card/AbilityCard.hpp"
#include "Card/DeckCard.hpp"
#include "GameManager/GameManager.hpp"
#include "Player/Player.hpp"
#include "Rules/Kombinasi.hpp"

int main()
{
    cout << "\033[2J\033[1;1H" << endl;
    cout <<" _______ _______ __   _ ______ __   __       _______ _______  ______ ______  _______"<<endl;
    cout << "|        |_____| | \\  | |     \\ \\___/        |       |_____| |_____/ |     \\ |______"<<endl;
    cout << "|_____   |     | |  \\_| |_____/   |          |_____  |     | |    \\_ |_____/ ______|"<<endl;
                                                                                    
    cout << "Masukkan metode pembuatan kartu (auto/file): " << endl;
    cout << ">> ";
    string makeCardMethod;
    cin >> makeCardMethod;
    GameManager* game;
    if(makeCardMethod == "auto"){
        game = new GameManager();
    }else{
        string fileName;
        game = new GameManager(fileName);
    }
    int round = 1;
    game->setRound(round);
    while(true){
        cout << "ROUND " << round << endl;
            // for each player give 2 cards from table cards

        if(round < 7 && round > 1){
            DeckCard temp = game->tableCards.takeCard();
            game->playCards+temp;
            cout<<"Kartu "<<temp.getNum()<<" "<<temp.translateToString()<<" telah ditambahkan di meja"<<endl;
        }

        for (int i = 0 ; i < 7 ; i++){
            //Implementasi penunjuk player yg main
            //CONTOH : "Sekarang saatnya Player I"
            cout << "Sekarang adalah giliran Player " << game->players.getPlayer(0).getName() << endl;
            if(round == 1){
                DeckCard temp1 = game->tableCards.takeCard();
                DeckCard temp2 = game->tableCards.takeCard();
                game->players.addPlayerCard(0, temp1);
                game->players.addPlayerCard(0, temp2);
                cout<<"Kamu dapat kartu "<<temp1.getNum()<<" "<<temp1.translateToString()<<endl;
                cout<<"Kamu dapat kartu "<<temp2.getNum()<<" "<<temp2.translateToString()<<endl;
                //Mulai aksi player                
                game->players.getPlayer(0).viewAllCard();
                cout<<endl;
            }

            bool input = false;
            while(!input){
                try{
                    cout<<"Tentukan aksi anda: "<<endl;
                    cout<<"1. Next"<<endl;
                    cout<<"2. Double"<<endl;
                    cout<<"3. Half"<<endl;
                    cout<<">> ";

                    string aksi;
                    cin>>aksi;
                    aksi = game->inputToLower(aksi);
                    //Implementasi poin disini
                    //pake getter dan setter poin yg di game manager
                    if (game->isInputTrue(aksi)){
                        if(aksi == "next"){
                            /* Do Nothing */
                        }else if(aksi == "double"){
                            game->setPoint(game->point*2);
                            cout << game->players.getPlayer(0).getName() << " melakukan DOUBLE! Poin hadiah naik dari " << game->point/2 << " menjadi " << game->point  << "!" << endl;
                        }else if(aksi == "half"){
                            game->setPoint(game->point/2);
                            if(game->point != 0){
                                cout << game->players.getPlayer(0).getName() << " melakukan HALF! Poin hadiah turun dari " << game->point*2 << " menjadi " << game->point  << "!" << endl;
                            }else{
                                cout << "Nothing happened" << endl;
                                game->setPoint(1);
                            }
                        }else if(aksi == "help"){
                            cout << "Berikut adalah beberapa perintah: " << endl;
                            cout << "1. Next"<< endl;
                            cout << "2. Double"<< endl;
                            cout << "3. Half"<< endl;
                            cout << "4. Quadruple" << endl;
                            cout << "5. Quarter" << endl;
                            cout << "6. Reroll" << endl;
                            cout << "7. Reverse "<< endl;
                            cout << "8. Switch" << endl;
                            cout << "9. Swap" << endl;
                            cout << "10. Help" << endl;
                            input = true;
                        }else{
                            if(aksi == game->players.getPlayer(0).getAbilityCard().getType()){
                                if(!game->players.getPlayer(0).isabilityCardEmpty()){
                                    game->manipulate<AbilityCard&>(game->players.getPlayer(0).getAbilityCard());
                                }else{
                                    cout << "Anda belum memiliki kartu ability" << endl;
                                }
                            }else{
                                throw "Anda tidak memiliki kartu ini!\n";
                            }
                        }
                        input = true;
                    }else{
                        throw "Input Anda salah, silakan ulangi!\n";
                    }
                }catch (const char* err){
                    cout << "Error: " << err << endl;
                }
            }
            cout << endl;
            game->players.nextTurn();
        }

        if(round == 1){
            // Give 1 ability card to each player
            /* TODO */
            cout<<"Ronde I telah berakhir"<<endl;
            DeckCard temp = game->tableCards.takeCard();
            game->playCards+temp;
            cout<<"Kartu "<<temp.getNum()<<" "<<temp.translateToString()<<" telah ditambahkan di meja"<<endl;
            cout<<endl;
            game->playCards.displayDeckCard();
            cout << endl;

            cout << "Pembagian Ability Card" << endl;
            for(int i = 0; i < 7 ; i++){
                AbilityCard* temp = game->abilityCardList.takeCard();
                game->players.addAbilityCard(i, *temp);
                cout << "Pemain " << game->players.getPlayer(i).getName() << " mendapatkan kartu ability: ";
                game->players.getPlayer(i).getAbilityCard().printInfo();
                // game->manipulate<AbilityCard&>(game->players.getPlayer(i).getAbilityCard());
            }
            cout << endl;
        }

        /* TOLONG CEK DI SINI*/ 
        if (round == 7)
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
        round++;
        game->setRound(round);
        // Ubah Turn

        if (round > 7)
        {
            break;
        }
        game->players.nextTurn();
    }
    return 0;
}