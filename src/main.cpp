#include <iostream>
// #include "Card/AbilityCard.hpp"
#include "Card/DeckCard.hpp"
#include "GameManager/GameManager.hpp"
#include "GameManager/CandyGameManager.hpp"
#include "GameManager/CapchaManager.hpp"
#include "Player/Player.hpp"
#include "Rules/Kombinasi.hpp"
using namespace std;

int main()
{
    cout << "\033[2J\033[1;1H" << endl;
    cout <<" _______ _______ __   _ ______ __   __       _______ _______  ______ ______  _______"<<endl;
    cout << "|        |_____| | \\  | |     \\ \\___/        |       |_____| |_____/ |     \\ |______"<<endl;
    cout << "|_____   |     | |  \\_| |_____/   |          |_____  |     | |    \\_ |_____/ ______|"<<endl;

    bool inputValid = false;
    string inputGame;
    while (!inputValid)
    {
        cout<<"Pilihan Game :"<<endl;
        cout<<"1. Capcha"<<endl;
        cout<<"2. Kartu Permen"<<endl;
        cout<<">> ";
        cin>>inputGame;
        if (inputGame == "1")
        {
            inputValid = true;
        }
        else if (inputGame == "2")
        {
            inputValid = true;
        }
        else
        {
            cout<<"Masukan tidak valid, silahkan ulangi."<<endl;
        }
    }
    cout<<inputGame<<endl;
    if (inputGame == "1")
    {
        //List Of Player
        deque<Player*> pointerArr;
        deque<Player*> temp;

        //Variables
        bool menang = false;
        string inputPlayer;

        //Capcha GM
        CapchaManager* game = new CapchaManager();
        cout<<"TEST"<<endl;
        for (int i = 0 ; i<4 ; i++)
        {
            for (int j = 0  ; j < 13 ; j++)
            {
                DeckCard tempCard;
                game->getTableCards()-tempCard;
                game->getPlayers().addPlayerCard(i, tempCard);
            }
        } 
        //Game
        for (int i = 0 ; i < 4 ; i++)
        {
            pointerArr.push_back(game->getPlayers().getPlayerAddress(i));
        }
        while (!menang)
        {
            while(!pointerArr.empty())
            {
                cout<<"Sekarang giliran player "<<pointerArr[0]->getName()<<endl;
                pointerArr[0]->viewAllCard();
                cout<<"Masukkan aksi :"<<endl;
                cout<<">> ";
                cin>>inputPlayer;

                if (inputPlayer == "1")
                {
                    cout<<"NEXT"<<endl;
                    temp.push_front(pointerArr.at(0));
                    pointerArr.pop_front();
                }
                else
                {
                    cout<<"IN"<<endl;
                    pointerArr.push_back(pointerArr.at(0));
                    pointerArr.pop_front();
                }
            }
            for(int i = 0 ; i < 4 ; i++)
            {
                pointerArr.push_back(temp.at(i));
            }
        }
    }
    else
    {
        cout << "Masukkan metode pembuatan kartu (auto/file): " << endl;
        cout << ">> ";
        string makeCardMethod;
        string fileName;
        cin >> makeCardMethod;
        CandyGameManager* game;
        if(makeCardMethod == "auto"){
            game = new CandyGameManager();
        }else{
            cin >> fileName;
            game = new CandyGameManager(fileName);
        }
        game->setRound(1);
        while(true){
            cout << "ROUND " << game->getRound() << endl;
                // for each player give 2 cards from table cards

            if(game->getRound() < 7 && game->getRound() > 1){
                DeckCard temp;
                game->getTableCards()-temp;
                game->getPlayCards()+temp;
                cout<<"Kartu "<<temp.getNum()<<" "<<temp.translateToString()<<" telah ditambahkan di meja"<<endl;
            }

            for (int i = 0 ; i < 7 ; i++){
                //Implementasi penunjuk player yg main
                //CONTOH : "Sekarang saatnya Player I"
                cout << "Sekarang adalah giliran Player " << game->getPlayers().getPlayer(0).getName() << endl;
                if(game->getRound() == 1){
                    DeckCard temp1, temp2;
                    game->getTableCards()-temp1;
                    game->getTableCards()-temp2;
                    game->getPlayers().addPlayerCard(0, temp1);
                    game->getPlayers().addPlayerCard(0, temp2);
                    cout<<"Kamu dapat kartu "<<temp1.getNum()<<" "<<temp1.translateToString()<<endl;
                    cout<<"Kamu dapat kartu "<<temp2.getNum()<<" "<<temp2.translateToString()<<endl;
                    //Mulai aksi player                
                    game->getPlayers().getPlayer(0).viewAllCard();
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
                            }else if(aksi == "double" || aksi == "2"){
                                game->setPoint(game->getPoint()*2);
                                cout << game->getPlayers().getPlayer(0).getName() << " melakukan DOUBLE! Poin hadiah naik dari " << game->getPoint()/2 << " menjadi " << game->getPoint()  << "!" << endl;
                            }else if(aksi == "half"){
                                game->setPoint(game->getPoint()/2);
                                if(game->getPoint() != 0){
                                    cout << game->getPlayers().getPlayer(0).getName() << " melakukan HALF! Poin hadiah turun dari " << game->getPoint()*2 << " menjadi " << game->getPoint()  << "!" << endl;
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
                            }else{
                                if(aksi == game->getPlayers().getPlayer(0).getAbilityCard().getType()){
                                    if(!game->getPlayers().getPlayer(0).isabilityCardEmpty()){
                                        game->manipulate<AbilityCard&>(game->getPlayers().getPlayer(0).getAbilityCard());
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
                        input = false;
                    }
                }
                cout << endl;
                cout << "NEXT TURN" << endl;
                game->getPlayers().nextTurn();
            }

            if(game->getRound() == 1){
                // Give 1 ability card to each player
                /* TODO */
                cout<<"Ronde I telah berakhir"<<endl;
                DeckCard temp;
                game->getTableCards()-temp;
                game->getPlayCards()+temp;
                cout<<"Kartu "<<temp.getNum()<<" "<<temp.translateToString()<<" telah ditambahkan di meja"<<endl;
                cout<<endl;
                game->getPlayCards().displayDeckCard();
                cout << endl;

                cout << "Pembagian Ability Card" << endl;
                for(int i = 0; i < 7 ; i++){
                    AbilityCard* temp;
                    game->getAbilityCardList()-temp;
                    game->getPlayers().addAbilityCard(i, *temp);
                    cout << "Pemain " << game->getPlayers().getPlayer(i).getName() << " mendapatkan kartu ability: ";
                    game->getPlayers().getPlayer(i).getAbilityCard().printInfo();
                    // game->manipulate<AbilityCard&>(game->getPlayers().getPlayer(i).getAbilityCard());
                }
                cout << endl;
            }

            /* TOLONG CEK DI SINI*/ 
            if (game->getRound() == 7)
            {
                vector<Kombinasi> tempKombinasi;
                for(int i = 0; i < 7 ; i++){
                    tempKombinasi.push_back(Kombinasi(game->getPlayers().getPlayer(i).getCard(),game->getPlayCards()));
                }

                int idx;
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
                cout<<"Menambahkan poin pada player "<<game->getPlayers().getPlayerAddress(idx)->getName()<<endl;
                cout<<"Sebesar "<<game->getPoint()<<endl;

                cout<<"Table Card List"<<endl;
                game->getPlayCards().displayDeckCard();

                cout<<"Player Card :"<<endl;
                for (int i = 0 ; i < 7 ; i++)
                {
                    cout<<"Player "<<i+1<<endl;
                    game->getPlayers().getPlayer(i).viewAllCard();
                }
                long long tempPoin = game->getPlayers().getPlayer(idx).getPoint();
                game->getPlayers().setPlayerPoint(idx,game->getPoint() + tempPoin);
            }
            game->setRound(game->getRound()+1);
            // Ubah Turn
            game->getPlayers().nextTurn();
            if (game->getRound() > 7)
            {
                /* SHOW LEADERBOARD */
                game->leaderboard();
                if(game->existWinner()){
                    cout << "WINNER FOUND" << endl;
                    /* OPSI BIKIN PERMAINAN BARU */
                    string option;
                    cout << "Ulang permainan? (Y/N)" << endl;
                    cin>>option;
                    if(option=="Y"){
                        /* reset */
                        delete game;
                        game->setRound(1);
                        if(makeCardMethod == "auto"){
                            game = new CandyGameManager();
                        }else{
                            game = new CandyGameManager(fileName);
                        }
                    }else{
                        delete game;
                        break;
                    }
                }else{
                    cout << "NO WINNER. STARTING FROM ROUND 1" << endl;

                    game->setRound(1);

                    game->reset();
                    
                    game->makeAbilityCards();

                    cout << "Masukkan metode pembuatan kartu (auto/file): " << endl;
                    cin >> makeCardMethod;
                    if(makeCardMethod == "auto"){
                        game->makeTableCards();
                    }else{
                        cin >> fileName;
                        game->makeTableCards(fileName);
                    }

                }
            }
        }
    }
    return 0;
}