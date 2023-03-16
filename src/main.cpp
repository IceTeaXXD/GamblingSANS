#include <iostream>
// #include "Card/AbilityCard.hpp"
#include "Card/DeckCard.hpp"
#include "GameManager/GameManager.hpp"
#include "GameManager/CandyGameManager.hpp"
#include "GameManager/CapchaManager.hpp"
#include "Player/Player.hpp"
#include "Player/ArrOfPlayer.hpp"
#include "Rules/Kombinasi.hpp"
#include "Rules/ArrOfKombinasi.hpp"
#include "Exception/Exception.hpp"

using namespace std;

int main()
{
    cout << "\033[2J\033[1;1H" << endl;
    cout << "\033[38;2;255;192;203m" << R"(
                                                 .                          
                                               *,**                         
                                                %.                          
                                                &*                          
                                     #@@%#%@@(  @,                          
                                &**/************&.(                         
                             (****************(*,,&*#                       
                            #(&@&%#(/,....,,,,,,,,,,.%*                     
                           %*******/******************/                     
                          #****************************.                    
                         @/**************@ .... ... %**/                    
                        /***************@...CANDY..%**(                    
                        &***************/...CARDS../***#                    
                       ****************, ........*,****#                    
                       &/**************@...  %(********#                    
                       ****************@..(**/*********#                    
                      @/***/&%*********%#&&#%%*********%                    
                      /**###(&*********/###%###&*******%                    
                     #**#####@*********/####@##@*******&                    
                     #*###&###*********/#######@/******@                
                    .*,..&#(,**********/####(#  ,******@          
)" << '\n' << "\033[0m";

    bool inputValid = false;
    string inputGame;
    while (!inputValid)
    {
        cout<<"Pilihan Game :"<<endl;
        cout<<"1. Capcha"<<endl;
        cout<<"2. Kartu Permen"<<endl;
        cout<<"3. UNO"<<endl;
        cout<<"4. Permainan 24" << endl;
        cout<<">> ";
        cin>>inputGame;
        if (inputGame == "1" || inputGame == "2" || inputGame == "3" || inputGame == "4")
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
        deque<CapsaGamePlayer*> pointerArr;
        deque<CapsaGamePlayer*> gamePlayer;

        //Variables
        bool menang = false;
        string inputPlayer;
        int angka;
        bool flag = true;
        KombinasiCapsa* droppedCombination;

        //Capcha GM
        CapchaManager* game = new CapchaManager();
        for (int i = 0 ; i<4 ; i++)
        {
            for (int j = 0  ; j < 13 ; j++)
            {
                DeckCard tempCard;
                game->operator-(tempCard);
                game->getPlayers().addPlayerCard(0, tempCard);
                // cout<<"Kamu dapat kartu "<<tempCard.translateToType()<<endl;
            }
            game->getPlayers().nextTurn();
            // cout<<"---------------"<<endl;
        } 
        //Game
        int idxFirstPlayer = game->firstPlayer();
        for (int i = idxFirstPlayer ; i < idxFirstPlayer+4 ; i++)
        {
            pointerArr.push_back(game->getPlayers().getPlayerAddress(i%4));
        }
        game->deleteAll3Cards();
        while (!menang)
        {
            ArrOfKombinasi tempArrKombinasi;
            if (flag)
            {
                cout<<"=============================================================================================="<<endl;
                cout<<"Sekarang giliran player "<<pointerArr[0]->getName()<<endl;
                cout<<"=============================================================================================="<<endl;
                cout<<"Banyak kartu anda : "<<pointerArr[0]->getCountOfPlayerCards()<<endl;
                cout << "Kartu kamu :\n";
                pointerArr[0]->viewAllCard();
                cout<<"List Kombinasi yang Anda punya"<<endl;
                tempArrKombinasi = ArrOfKombinasi(pointerArr[0]->getCard());
                tempArrKombinasi.displayCombinationList();
                cout<<"=============================================================================================="<<endl;
                cout<<"Masukkan Nama Kombinasi yang ingin dikeluarkan (Tanpa Spasi):"<<endl;
                cout<<">> ";    
                cin >> inputPlayer;       
                while (inputPlayer!="HighCard"&&inputPlayer!="Pair"&&inputPlayer!="TwoPair"&&\
                       inputPlayer!="ThreeAKind"&&inputPlayer!="Straight"&&inputPlayer!="Flush"&&\
                       inputPlayer!="FullHouse"&&inputPlayer!="FourAKind"&&inputPlayer!="StraightFlush")
                {
                    cout << "Input salah. Ketik nama kombinasi seperti pada layar tanpa spasi.\n";
                    cout<<">> ";
                    cin >> inputPlayer;
                }
                tempArrKombinasi.displaySpecificCombination(inputPlayer);
                cout<<"Masukkan nomor kombinasi yang ingin dikeluarkan : "<<endl;
                cout<<">> ";
                cin>>angka;
                while(angka > tempArrKombinasi.dropCombSize() && angka <= 0)
                {
                    cout<<"Masukkan nomor kombinasi yang ingin dikeluarkan : "<<endl;
                    cout<<">> ";
                    cin>>angka;
                }
                game->setDroppedCombination(tempArrKombinasi.DropCombination(angka-1));
                // cout<<game->getDroppedCombination().getCName()<<endl;
                *pointerArr[0]-game->getDroppedCombination();
                pointerArr[0]->setArrCombination();
                // game->getDroppedCombination().printKombinasi();
                game->setLastPlayed(game->getDroppedCombination());
                ArrOfKombinasi newArrKombinasi = ArrOfKombinasi(pointerArr[0]->getCard());
                // newArrKombinasi.displaySpecificCombination("HighCard");
                flag = false;
                // cout<<pointerArr[0]->getCountOfPlayerCards()<<" JUMLAH KARTU"<<endl;
                if(pointerArr[0]->getCountOfPlayerCards() == 0)
                {
                    menang = true;
                    cout<<"Player "<<pointerArr[0]->getName()<<" telah memenangkan pertandingan"<<endl;
                    break;
                }
                pointerArr.push_back(pointerArr.at(0));
                pointerArr.pop_front();
                cout<<"=============================================================================================="<<endl;
            }
            do
            {
                 cout << "\033[2J\033[1;1H" << endl;
                cout<<"=============================================================================================="<<endl;
                cout<<"Sekarang giliran player "<<pointerArr[0]->getName()<<endl;
                cout<<"=============================================================================================="<<endl;
                cout<<"Kombinasi sebelumnya : "<<endl;
                game->getDroppedCombination().printKombinasi();
                cout<<"=============================================================================================="<<endl;
                // cout<<endl;
                pointerArr[0]->getAllGreaterCombination(game->getDroppedCombination());
                if (pointerArr[0]->isGreater())
                {
                    cout<<"Banyak kartu anda : "<<pointerArr[0]->getCountOfPlayerCards()<<endl;
                    cout << "Kartu kamu :\n";
                    pointerArr[0]->viewAllCard();
                    pointerArr[0]->displayGreaterComb();
                    cout<<"Masukkan '0' untuk PASS atau Masukkan nomor kombinasi yang ingin dikeluarkan"<<endl;
                    cout<<"Masukkan aksi :"<<endl;
                    cout<<">> ";
                    cin>>angka;
                    if (angka == 0)
                    {
                        gamePlayer.push_front(pointerArr.at(0));
                        pointerArr.pop_front();
                        cout<<"Anda melakukan PASS"<<endl;
                    }
                    else
                    {
                        // cout<<"P1"<<endl;
                        // tempArrKombinasi = ArrOfKombinasi(pointerArr[0]->getCard());
                        game->setDroppedCombination(pointerArr[0]->getGreaterComb(angka-1));
                        cout<<"CEK 1"<<endl;
                        cout<<"INI YANG DI GAME SETELAH UPDATE"<<endl;
                        game->getDroppedCombination().printKombinasi();
                        *pointerArr[0]-(game->getDroppedCombination());
                        pointerArr[0]->setArrCombination();
                        cout<<pointerArr[0]->getCountOfPlayerCards()<<" JUMLAH KARTU"<<endl;
                        cout<<"CEK 2"<<endl;
                        cout<<"INI YANG DI GAME SETELAH UPDATE"<<endl;
                        game->getDroppedCombination().printKombinasi();
                        // cout<<pointerArr[0]->getCountOfPlayerCards()<<endl;
                        game->setLastPlayed(game->getDroppedCombination());
                        cout<<"CEK 3"<<endl;
                        cout<<"INI YANG DI GAME SETELAH UPDATE"<<endl;
                        game->getDroppedCombination().printKombinasi();
                        if(pointerArr[0]->getCountOfPlayerCards() == 0)
                        {
                            menang = true;
                            cout<<"Player "<<pointerArr[0]->getName()<<" telah memenangkan pertandingan"<<endl;
                            break;
                        }
                        pointerArr.push_back(pointerArr.at(0));
                        pointerArr.pop_front();
                    }
                }
                else
                {
                    cout<<"Anda dipaksa untuk PASS"<<endl;
                    cout<<"Banyak kartu anda : "<<pointerArr[0]->getCountOfPlayerCards()<<endl;
                    cout << "Kartu kamu :\n";
                    pointerArr[0]->viewAllCard();
                    gamePlayer.push_front(pointerArr.at(0));
                    pointerArr.pop_front();
                }
                // cout<<"========================================================="<<endl;
            }
            while(!pointerArr.empty());
            // cout << "aaaaaaa\n";
            pointerArr.clear();
            for(int i = 0 ; i < 4 ; i++)
            {
                // cout << i << "-------------------" << gamePlayer.size() << endl;
                pointerArr.push_back(gamePlayer.at(i));
            }
            gamePlayer.clear();
            flag = true;
        }
    }
    else if(inputGame == "2")
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
                if(game->getRound()!=1)
                {
                    game->displayMeja();
                }
                cout << "Sekarang adalah giliran Player " << game->getPlayers().getPlayer(0).getName() << endl;
                if(game->getRound() == 1){
                    DeckCard temp1, temp2;
                    game->operator-(temp1);
                    game->operator-(temp2);
                    game->getPlayers().addPlayerCard(0, temp1);
                    game->getPlayers().addPlayerCard(0, temp2);
                    cout<<"Kamu dapat kartu : " << endl;
                    temp1.printInfo();
                    cout << endl;
                    temp2.printInfo();
                    cout << endl;
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
                        input = game->parseCommand(aksi);
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
                cout << "Ronde VI telah berakhir" << endl;
                game->displayMeja();
                for(int i = 0; i<7; i++)
                {
                    cout << "Player " << game->getPlayers().getPlayer(i).getName() << endl;
                    game->getPlayers().getPlayer(i).viewAllCard();
                    cout << endl;
                }
                int idx = game->getPlayers().calculateMax(game->getPlayCards().getBuffer(),game->getPoint());
                long long tempPoin = game->getPlayers().getPlayer(idx).getPoint();
                game->getPlayers().setPlayerPoint(idx,game->getPoint() + tempPoin);
            }
            cout << endl;
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
    else if (inputGame == "3")
    {
        /* UNO */
    }
    else if(inputGame == "4")
    {
        // TwentyFourGameManager* game = new TwentyFourGameManager();
        // cout << "Insert your solution!" << endl;
        // string solution;
        // cin >> solution;
        // game->findTwentyFour();
        // for(int i = 0; i < game->getNumSolution(); i++){
        //     cout << game->getSolution(i) << endl;
        // }
        // game->parseCommand(solution);
    }
    return 0;
}