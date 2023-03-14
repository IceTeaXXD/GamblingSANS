#include <iostream>
// #include "Card/AbilityCard.hpp"
#include "Card/DeckCard.hpp"
#include "GameManager/GameManager.hpp"
#include "GameManager/CandyGameManager.hpp"
#include "GameManager/CapchaManager.hpp"
#include "Player/Player.hpp"
#include "Player/ArrOfPlayer.hpp"
#include "Rules/Kombinasi.hpp"
#include "Exception/Exception.hpp"
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
                game->operator-(tempCard);
                // game->getPlayers().addPlayerCard(i, tempCard);
            }
        } 
        //Game
        for (int i = 0 ; i < 4 ; i++)
        {
            // pointerArr.push_back(game->getPlayers().getPlayerAddress(i));
        }
        while (!menang)
        {
            while(!pointerArr.empty())
            {
                cout<<"Sekarang giliran player "<<pointerArr[0]->getName()<<endl;
                // pointerArr[0]->viewAllCardCapsa();
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
        cout << "\033[2J\033[1;1H" << endl;
        cout << "====================" << endl;
        cout << " GAME: KARTU PERMEN " << endl;
        cout << "====================" << endl;
        cout << "Masukkan metode pembuatan kartu (auto/file):" << endl;
        cout << ">> ";
        string makeCardMethod;
        string fileName;
        cin >> makeCardMethod;
        for(int i = 0; i < makeCardMethod.length(); i++)
        {
            makeCardMethod[i] =  tolower(makeCardMethod[i]);
        }
        CandyGameManager* game;
        if(makeCardMethod == "auto"){
            game = new CandyGameManager();
        }else{
            cout << "Masukkan nama file: ";
            cin >> fileName;
            game = new CandyGameManager(fileName);
        }
        game->setRound(1);
        cout << "\033[2J\033[1;1H" << endl;
        while(true){
            cout << "ROUND " << game->getRound() << endl;

            if(game->getRound() < 6 && game->getRound() > 1){
                DeckCard temp;
                game->operator-(temp);
                game->getPlayCards()+temp;
                cout<<"Kartu ";
                temp.printInfo(); 
                cout << " telah ditambahkan di meja"<<endl;
            }

            for (int i = 0 ; i < 7 ; i++){
                game->setTurn(i);
                cout << "Sekarang adalah giliran Player " << game->getPlayers().getPlayer(0).getName() << endl;
                if(game->getRound() == 1){
                    DeckCard temp1, temp2;
                    game->operator-(temp1);
                    game->operator-(temp2);
                    game->getPlayers().addPlayerCard(0, temp1);
                    game->getPlayers().addPlayerCard(0, temp2);
                    cout<<"Kamu dapat kartu : " << endl;
                    temp1.printInfo();
                    cout << "\n";
                    temp2.printInfo();
                    cout << "\n";
                }

                bool input = false;
                while(!input){
                    try{
                        cout<<"Tentukan aksi anda: (Point hadiah: " << game->getPoint() << ")"<<endl;
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
                                input = true;
                            }else if(aksi == "double" || aksi == "2"){
                                game->setPoint(game->getPoint()*2);
                                cout << game->getPlayers().getPlayer(0).getName() << " melakukan DOUBLE! Poin hadiah naik dari " << game->getPoint()/2 << " menjadi " << game->getPoint()  << "!" << endl;
                                input = true;
                            }else if(aksi == "half"){
                                game->setPoint(game->getPoint()/2);
                                if(game->getPoint() != 0){
                                    cout << game->getPlayers().getPlayer(0).getName() << " melakukan HALF! Poin hadiah turun dari " << game->getPoint()*2 << " menjadi " << game->getPoint()  << "!" << endl;
                                }else{
                                    cout << "Nothing happened" << endl;
                                    game->setPoint(1);
                                }
                                input = true;
                            }else if(aksi == "viewcards"){
                                game->getPlayers().getPlayer(0).viewAllCard();
                                cout << endl;
                                input == false;
                            }else if(aksi == "tablecards"){
                                cout << " ==================== " << endl;
                                cout << "       DECK CARDS       " << endl;
                                cout << " ==================== " << endl;
                                game->getPlayCards().displayDeckCard();
                                cout << endl;
                                input == false;
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
                                cout << "11. ViewCards" << endl;
                                cout << "12. TableCards" << endl;
                                cout << endl;
                            }else{
                                if(game->getPlayers().getPlayer(0).getHasAbility()){
                                    if(aksi == game->getPlayers().getPlayer(0).getAbilityCard().getType()){
                                        game->manipulate<AbilityCard&>(game->getPlayers().getPlayer(0).getAbilityCard());
                                    }else{
                                        throw TidakPunyaKartuAbility();
                                    }
                                    input = true;
                                }else{
                                    throw BelumAdaAbility();
                                }
                                input = true;
                            }
                        }else{
                            throw InputSalah();
                        }
                    }catch(Exception& e){
                        e.what();
                        input = false;
                    }
                }
                cout << endl;
                // cout << "\033[2J\033[1;1H" << endl;
                game->getPlayers().nextTurn();
            }

            if(game->getRound() == 1){
                // Give 1 ability card to each player
                /* TODO */
                cout<<"Ronde I telah berakhir"<<endl;
                DeckCard temp;
                game->operator-(temp);
                game->getPlayCards()+temp;
                cout<<"Kartu ";
                temp.printInfo(); 
                cout << " telah ditambahkan di meja"<<endl;
                cout<<endl;

                cout << "Pembagian Ability Card sudah dilakukan! :D" << endl;
                for(int i = 0; i < 7 ; i++){
                    AbilityCard* temp;
                    game->getAbilityCardList()-temp;
                    game->getPlayers().addAbilityCard(i, *temp);
                }
                cout << endl;
            }

            if (game->getRound() == 6)
            {
                map<double, Kombinasi> mapValue;
                map<int, Player> mapPlayer;
                map<int, Kombinasi> mapIndeks;
                for(int i = 0; i < 7 ; i++){
                    mapIndeks.insert(make_pair(i, Kombinasi(game->getPlayers().getPlayer(i).getCard(),game->getPlayCards().getBuffer())));
                    mapValue.insert(make_pair(Kombinasi(game->getPlayers().getPlayer(i).getCard(),game->getPlayCards().getBuffer()).value(), Kombinasi(game->getPlayers().getPlayer(i).getCard(),game->getPlayCards().getBuffer())));
                    mapPlayer.insert(make_pair(i, game->getPlayers().getPlayer(i)));
                }
                double maxValue = maxKeyMap<double, Kombinasi>(mapValue);
                int idx = findKey<int, Kombinasi>(mapIndeks, mapValue[maxValue]);
                cout<<"Nilai Tertinggi yaitu "<<maxValue<<endl;
                cout<<"Dengan kombinasi "<<mapValue[maxValue].getCombinationName()<<endl;
                cout<<"Menambahkan poin pada player "<<mapPlayer[idx].getName()<<endl;
                cout<<"Sebesar "<<game->getPoint()<<endl;

                long long tempPoin = mapPlayer[idx].getPoint();
                game->getPlayers().setPlayerPoint(idx,game->getPoint() + tempPoin);

                cout<<"Table Card List"<<endl;
                game->getPlayCards().displayDeckCard();
                cout<<"\nPlayer Cards :"<<endl;
                for (int i = 0 ; i < 7 ; i++)
                {
                    cout<<"Player "<<game->getPlayers().getPlayerAddress(i)->getName()<<endl;
                    game->getPlayers().getPlayer(i).viewAllCard();
                    cout << endl;
                }

            }
            game->setRound(game->getRound()+1);
            // Ubah Turn
            game->getPlayers().nextTurn();
            if (game->getRound() > 6)
            {
                /* SHOW LEADERBOARD */
                game->leaderboard();
                if(game->existWinner()){
                    cout << "WINNER FOUND" << endl;
                    /* OPSI BIKIN PERMAINAN BARU */
                    string option;
                    cout << "Ulang permainan? (Y/N)" << endl;
                    cin>>option;
                    cout << "\033[2J\033[1;1H" << endl;
                    if(option=="Y"){
                        /* reset */
                        delete game;
                        cout << "Masukkan metode pembuatan kartu (auto/file):\n>> ";
                        cin >> makeCardMethod;
                        if(makeCardMethod == "auto"){
                            game = new CandyGameManager();
                        }else{
                            cout << "Masukkan nama file: ";
                            cin >> fileName;
                            game = new CandyGameManager(fileName);
                        }
                        game->setRound(1);
                        cout << "\033[2J\033[1;1H" << endl;
                    }else{
                        delete game;
                        break;
                    }
                }else{
                    cout << "NO WINNER. STARTING FROM ROUND 1" << endl;

                    game->setRound(1);

                    game->reset();
                    
                    game->makeAbilityCards();

                    cout << "Masukkan metode pembuatan kartu (auto/file):\n>> ";
                    cin >> makeCardMethod;
                    for(int i = 0; i < makeCardMethod.length(); i++)
                    {
                        makeCardMethod[i] =  tolower(makeCardMethod[i]);
                    }
                    if(makeCardMethod == "auto"){
                        game->makeTableCards();
                    }else{
                        cout << "Masukkan nama file: ";
                        cin >> fileName;
                        game->makeTableCards(fileName);
                    }
                    cout << "\033[2J\033[1;1H" << endl;
                }
            }
        }
    }
    return 0;
}