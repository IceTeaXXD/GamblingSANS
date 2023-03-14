#include "CandyGameManager.hpp"
#include "../Exception/Exception.hpp"

CandyGameManager::CandyGameManager()
{
    abilityCardList.MakeDeck();
    players = new ArrOfPlayer<CandyGamePlayer>(7);
}
CandyGameManager::CandyGameManager(string f) : GameManager(f)
{
    abilityCardList.MakeDeck();
    players = new ArrOfPlayer<CandyGamePlayer>(7);
}

ArrOfPlayer<CandyGamePlayer>& CandyGameManager::getPlayers()
{
    return *players;
}

void CandyGameManager::displayPlayer()
{
    for (int i = 0 ; i < 7 ; i++)
    {
        cout << "Player Number " << i+1 << players->getPlayer(i).getName() << endl;
    }
}

CardCollection<AbilityCard*>& CandyGameManager::getAbilityCardList()
{
    return abilityCardList;
}
CardCollection<DeckCard>& CandyGameManager::getPlayCards()
{
    return playCards;
}

void CandyGameManager::leaderboard(){
    cout << "LEADERBOARD" << endl;
    for (int i = 0; i < 7 ; i++){
        cout << i+1;
        cout << ". ";
        cout << players->getPlayer(i).getName();
        cout << ": ";
        cout << players->getPlayer(i).getPoint() << endl;
    }
    cout << endl;
}

bool CandyGameManager::existWinner(){
    for (int i = 0; i < 7 ; i++){
        if(players->getPlayer(i).getPoint() >= 4294967296){
            return true;
        }
    }
    return false;
}

void CandyGameManager::reset()
{
    /* DELETE DECK, DELETE KARTU PER PLAYER, DELETE TABLE CARD, DELETE ABILITY CARD, ULANG DARI round 1 */
    playCards.clear();
    abilityCardList.clear();
    buffer.clear();
    setPoint(64);
    for(int i = 0; i < 7;i++){
        players->clearCard(i);
        players->getPlayerAddress(i)->setHasAbility(false);
    }
}

void CandyGameManager::makeAbilityCards()
{
    abilityCardList.MakeDeck();
}

template<>
void CandyGameManager::manipulate<REROLL&>(REROLL& C){
    if (C.isAvailable())
    {
        C.setNotAvailable();

        /* Kosongkan Kartu terlebih dahulu */
        players->clearCard(0);

        /* Tambahin Kartu Baru */
        DeckCard temp1,temp2;
        CardCollection<DeckCard>::operator-(temp1);
        CardCollection<DeckCard>::operator-(temp2);
        players->addPlayerCard(0, temp1);
        players->addPlayerCard(0, temp2);

        /* OUTPUT */
        cout<<"RE-ROLLED"<<endl;
        cout << "Kartu anda sekarang : " << endl;
        temp1.printInfo();
        cout << "\n";
        temp2.printInfo();
    }
    else
    {
        cout << "Kartu anda telah dimatikan" << endl;
    }
}

template <>
void CandyGameManager::manipulate<Quadruple&>(Quadruple& C){
    if (C.isAvailable()){
        C.setNotAvailable();

        /* Set point jadi 4 kali */
        setPoint(this->point*4);

        /* OUTPUT */
        cout << "Point berubah menjadi " << this->point << endl;
    }
    else{
        cout << "Kartu anda telah dimatikan" << endl;
    }
}

template<>
void CandyGameManager::manipulate<Quarter&>(Quarter& C){
    if (C.isAvailable()){
        C.setNotAvailable();

        /* Set point jadi 1/4 */
        if(this->point > 1){
            setPoint(this->point/4);

            /* OUTPUT */
            cout << "Point berubah menjadi " << this->point << endl;
        }else{
            cout << "Nothing happened" << endl;
        }
    }
    else{
        cout << "Kartu anda telah dimatikan" << endl;
    }
}

template<>
void CandyGameManager::manipulate<ReverseDirection&>(ReverseDirection& C){
    if (C.isAvailable()){
        C.setNotAvailable();

        cout << "Player " << players->getPlayer(0).getName() << " melakukan REVERSE!." << endl;

        /* OUTPUT GILIRAN RONDE INI */
        ArrOfPlayer <CandyGamePlayer> before = *players;
        for(int i = 0 ; i < 7-turn ; i++){
            before.nextTurn();
        }
        cout << "Urutan eksekusi giliran saat ini : ";
        for (int i = 0; i < 7; i++){
            cout << before.getPlayer(i).getName() << " ";
        }
        cout << endl;

        /* Reverse direction */
        ArrOfPlayer<CandyGamePlayer> temp = *players;
        temp.reverseTurn(this->turn);

        /* OUTPUT GILIRAN RONDE SELANJUTNYA*/
        ArrOfPlayer <CandyGamePlayer> after = temp;
        for(int i = 0 ; i <= 7-turn ; i++){
            after.nextTurn();
        }
        cout << "Urutan eksekusi giliran selanjutnya : ";
        for (int i = 0; i < 7; i++){
            cout << after.getPlayer(i).getName() << " ";
        }
        cout << endl;
        bool input = false;
        while(!input){
            try{
                string aksi;
                cout<<"Tentukan aksi anda: (Point hadiah: " << getPoint() << ")"<<endl;
                cout<<"1. Next"<<endl;
                cout<<"2. Double"<<endl;
                cout<<"3. Half"<<endl;
                cout<<">> ";
                cin >> aksi;
                input = parseCommand(aksi);
            }catch (Exception& e){
                e.what();
                input = false;
            }
        }

        players->reverseTurn(this->turn);

        // throw ReverseNext();
    }
    else{
        throw KartuDimatikan();
    }
}

template<>
void CandyGameManager::manipulate<SwapCard&>(SwapCard& C){
    if (C.isAvailable()){
        C.setNotAvailable();

        cout << players->getPlayer(0).getName() << " melakukan SWAPCARD." << endl;
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
        for (int i = 1; i < 7; i++){
            cout << i << ". " << players->getPlayer(i).getName() << endl;
        }
        int pilihan1;
        cout << ">> ";
        cin >> pilihan1;
        if(pilihan1 > 7 && pilihan1 < 1){
            throw InputSalah();
        }else{
            cout << "Silahkan pilih pemain lain yang kartunya ingin anda tukar:" << endl;
            for (int i = 1; i < 7; i++){
                if (i != pilihan1){
                    cout << i << ". " << players->getPlayer(i).getName() << endl;
                }
            }
        }
        int pilihan2;
        cout << ">> ";
        cin >> pilihan2;
        if(pilihan2> 7 && pilihan2 < 1 && pilihan2 == pilihan1){
            throw InputSalah();
        }else{
            cout << "Silakan pilih kartu kanan/kiri " << players->getPlayer(pilihan1).getName() << ":" << endl;
            cout << "1. Kanan" << endl;
            cout << "2. Kiri" << endl;
            int pilihan3;
            cout << ">> ";
            cin >> pilihan3;
            cout << "Silakan pilih kartu kanan/kiri " << players->getPlayer(pilihan2).getName() << ":" << endl;
            cout << "1. Kanan" << endl;
            cout << "2. Kiri" << endl;
            int pilihan4;
            cout << ">> ";
            cin >> pilihan4;

            // move to a temp card first
            DeckCard p1Left = players->getPlayer(pilihan1).getLeftCard();
            DeckCard p1Right = players->getPlayer(pilihan1).getRightCard();
            DeckCard p2Left = players->getPlayer(pilihan2).getLeftCard();
            DeckCard p2Right = players->getPlayer(pilihan2).getRightCard();
            
            // cout << "============================" << endl;
            // cout << "KARTU SEBELUM DITUKAR : " << endl;
            // cout << players->getPlayer(pilihan1).getName() << endl;
            // players->getPlayer(pilihan1).viewAllCard();
            // cout << players->getPlayer(pilihan2).getName() << endl;
            // players->getPlayer(pilihan2).viewAllCard();

            // swap the card and remove swappee card
            if (pilihan3 == 1){
                if (pilihan4 == 1){
                    players->setPlayerRightCard(pilihan1, p2Right);
                    players->setPlayerRightCard(pilihan2, p1Right);
                }
                else{
                    players->setPlayerRightCard(pilihan1, p2Left);
                    players->setPlayerLeftCard(pilihan2, p1Right);

                }
            }
            else{
                if (pilihan4 == 1){
                    players->setPlayerLeftCard(pilihan1, p2Right);
                    players->setPlayerRightCard(pilihan2, p1Left);
                }
                else{
                    players->setPlayerLeftCard(pilihan1, p2Left);
                    players->setPlayerLeftCard(pilihan2, p1Left);
                }
            }
            
            // cout << "============================" << endl;
            // cout << "KARTU SETELAH DITUKAR : " << endl;
            // cout << players->getPlayer(pilihan1).getName() << endl;
            // players->getPlayer(pilihan1).viewAllCard();
            // cout << players->getPlayer(pilihan2).getName() << endl;
            // players->getPlayer(pilihan2).viewAllCard();
            // cout << "============================" << endl;
                
            /* OUTPUT */
            cout << "Kartu berhasil ditukar" << endl;
        }
    }
    else{
        cout << "Kartu anda telah dimatikan" << endl;
    }
}

template<>
void CandyGameManager::manipulate<Switch&>(Switch& C){
    if (C.isAvailable()){
        C.setNotAvailable();

        cout << players->getPlayer(0).getName() << " melakukan SWITCH." << endl;
        players->getPlayer(0).viewAllCard();
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
        for (int i = 1; i < 7; i++){
            cout << i << ". " << players->getPlayer(i).getName() << endl;
        }
        int pilihan1;
        cout << ">> ";
        cin >> pilihan1;
        if(pilihan1 > 7 && pilihan1 < 1){
            throw "Input Anda salah!\n";
        }else{
            cout << "Kedua kartu " << players->getPlayer(0).getName() << " telah ditukar dengan " << players->getPlayer(pilihan1).getName() << "!" << endl;

            // Get the cards
            DeckCard p1Left = players->getPlayer(0).getLeftCard();
            DeckCard p1Right = players->getPlayer(0).getRightCard();
            DeckCard p2Left = players->getPlayer(pilihan1).getLeftCard();
            DeckCard p2Right = players->getPlayer(pilihan1).getRightCard();

            // Switch card
            players->setPlayerLeftCard(0, p2Left);
            players->setPlayerRightCard(0, p2Right);
            players->setPlayerLeftCard(pilihan1, p1Left);
            players->setPlayerRightCard(pilihan1, p1Right);

            cout << "Kartumu sekarang adalah:" << endl;
            p2Left.printInfo();
            cout << "\n";
            p2Right.printInfo();
        }
    }
    else{
        cout << "Oops, kartu ability switchmu telah dimatikan sebelumnya :(.\nSilahkan lakukan perintah lain."<<endl;
    }
}

template<>
void CandyGameManager::manipulate<Abilityless&>(Abilityless& C){
    if (C.isAvailable()){
        C.setNotAvailable();
        cout << players->getPlayer(0).getName() << " akan mematikan kartu ability lawan!" << endl;
        cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan:" << endl;
        for (int i = 1; i < 7; i++){
            cout << i << ". " << players->getPlayer(i).getName() << endl;
        }
        int pilihan1;
        cout << ">> ";
        cin >> pilihan1;
        if(pilihan1 > 7 && pilihan1 < 1){
            throw InputSalah();
        }else{
            if (players->getPlayer(pilihan1).getAbilityCard().isAvailable()){
                players->getPlayer(pilihan1).getAbilityCard().setNotAvailable();
                cout << "Kartu ability " << players->getPlayer(pilihan1).getName() << " telah dimatikan." << endl;
            }
            else if(!players->getPlayer(1).getAbilityCard().isAvailable() && 
                    !players->getPlayer(2).getAbilityCard().isAvailable() && 
                    !players->getPlayer(3).getAbilityCard().isAvailable() && 
                    !players->getPlayer(4).getAbilityCard().isAvailable() && 
                    !players->getPlayer(5).getAbilityCard().isAvailable() && 
                    !players->getPlayer(6).getAbilityCard().isAvailable()){
                cout << "Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia 😭😭" << endl;
            }
            else if (!players->getPlayer(pilihan1).getAbilityCard().isAvailable()){
                cout << "Kartu ability " << players->getPlayer(pilihan1).getName() << " telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia 🙁" << endl;
            }
        }
    }
    else{
        throw TidakPunyaKartuAbility();
    }
}

template<>
void CandyGameManager::manipulate<AbilityCard&>(AbilityCard& C){
    if (C.getType() == "quadruple"){
        manipulate<Quadruple&>(dynamic_cast<Quadruple&>(C));
    }
    else if (C.getType() == "reverse"){
        manipulate<ReverseDirection&>(dynamic_cast<ReverseDirection&>(C));
    }
    else if (C.getType() == "reroll"){
        manipulate<REROLL&>(dynamic_cast<REROLL&>(C));
    }
    else if (C.getType() == "quarter"){
        manipulate<Quarter&>(dynamic_cast<Quarter&>(C));
    }
    else if (C.getType() == "swap"){
        manipulate<SwapCard&>(dynamic_cast<SwapCard&>(C));
    }
    else if (C.getType() == "switch"){
        manipulate<Switch&>(dynamic_cast<Switch&>(C));
    }
    else if (C.getType() == "abilityless"){
        manipulate<Abilityless&>(dynamic_cast<Abilityless&>(C));
    }else{
        throw TidakPunyaKartuAbility();
    }
}

bool CandyGameManager::parseCommand(string aksi)
{
    if(!isInputTrue(aksi)){
        throw InputSalah();
    }else{
        if(aksi == "next"){
            /* Do Nothing */
            return true;
        }else if(aksi == "double" || aksi == "2"){
            setPoint(getPoint()*2);
            cout << getPlayers().getPlayer(0).getName() << " melakukan DOUBLE! Poin hadiah naik dari " << getPoint()/2 << " menjadi " << getPoint()  << "!" << endl;
            return true;
        }else if(aksi == "half"){
            setPoint(getPoint()/2);
            if(getPoint() != 0){
                cout << getPlayers().getPlayer(0).getName() << " melakukan HALF! Poin hadiah turun dari " << getPoint()*2 << " menjadi " << getPoint()  << "!" << endl;
            }else{
                cout << "Nothing happened" << endl;
                setPoint(1);
            }
            return true;
        }else if(aksi == "viewcards"){
            getPlayers().getPlayer(0).viewAllCard();
            cout << endl;
            return false;
        }else if(aksi == "tablecards"){
            cout << " ==================== " << endl;
            cout << "       DECK CARDS       " << endl;
            cout << " ==================== " << endl;
            getPlayCards().displayDeckCard();
            cout << endl;
            return false;
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
            return false;
        }else{
            if(getPlayers().getPlayer(0).getHasAbility()){
                if(aksi == getPlayers().getPlayer(0).getAbilityCard().getType()){
                    manipulate<AbilityCard&>(getPlayers().getPlayer(0).getAbilityCard());
                }else{
                    throw TidakPunyaKartuAbility();
                }
                return true;
            }else{
                throw BelumAdaAbility();
            }
            return true;
        }
    }
}