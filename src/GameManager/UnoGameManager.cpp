#include "UnoGameManager.hpp"

UnoGameManager::UnoGameManager(){
    deckCards.MakeDeck();
    players = new ArrOfPlayer<UnoGamePlayer>();
}

void UnoGameManager::reset(){
    deckCards.clear();
    deckCards.MakeDeck();
    playCard.clear();
    players = new ArrOfPlayer<UnoGamePlayer>();
}

ArrOfPlayer<UnoGamePlayer>& UnoGameManager::getPlayers(){
    return *players;
}

CardCollection<UnoCard*>& UnoGameManager::getPlayCard(){
    return playCard;
}

CardCollection<UnoCard*>& UnoGameManager::getDeckCard(){
    return deckCards;
}

UnoGameManager::~UnoGameManager(){}

void UnoGameManager::distributeCard(){
    for (int i = 0; i < 5; i++){ // 5 cards
        for (int j = 0; j < 4; j++){ // 4 players
            UnoCard* temp = deckCards.getCard(0);
            players->addPlayerCard(j, *temp);
            deckCards-temp;
        }
    }
    UnoCard* temp = deckCards.getCard(0);
    playCard+temp;
    deckCards-temp;
    while (temp->getCardType() != "Play"){
        deckCards+temp;
        playCard-temp;
        temp = deckCards.getCard(0);
        playCard+temp;
        deckCards-temp;
    }
}

template<>
void UnoGameManager::manipulate<plus2&>(plus2& card){
    // for (int i = 0 ; i < players->getPlayer(1).getBuffer().size(); i++){
    //     if (players->getPlayer(1).getBuffer().at(i)->getCardType() == "plus2"){
    //         players->nextTurn();
    //         return;
    //     }
    // }
    for (int i = 0; i < 2; i++){
        UnoCard* temp = deckCards.getCard(0);
        players->addPlayerCard(1, *temp);
        deckCards-temp;
    }
}

template<>
void UnoGameManager::manipulate<reversecard&>(reversecard& card){
    if(players->getSize() == 2){
        players->nextTurn();
    }else{
    players->reverseTurn(0);
    players->prevTurn();
    }
}

template<>
void UnoGameManager::manipulate<skip&>(skip& card){
    players->nextTurn();
}

template<>
void UnoGameManager::manipulate<wildcard&>(wildcard& card){
    cout << "Pilih Warna: " << endl;
    pc.printGreen("1. Hijau");
    cout << endl;
    pc.printBlue("2. Biru");
    cout << endl;
    pc.printYellow("3. Kuning");
    cout << endl;
    pc.printRed("4. Merah");
    cout << endl;

    int color;
    cout << ">> ";
    cin >> color;
    playCard - playCard.getBuffer()[0];
    UnoCard* temp = new wildcard();
    temp->setWarna(color);
    playCard + temp;
}

template<>
void UnoGameManager::manipulate<wildcardplus4&>(wildcardplus4& card){
    cout << "Pilih Warna: " << endl;
    pc.printGreen("1. Hijau");
    cout << endl;
    pc.printBlue("2. Biru");
    cout << endl;
    pc.printYellow("3. Kuning");
    cout << endl;
    pc.printRed("4. Merah");
    cout << endl;

    int color;
    cout << ">> ";
    cin >> color;

    for (int i = 0; i < 4; i++){
        UnoCard* temp = deckCards.getCard(0);
        players->addPlayerCard(1, *temp);
        deckCards-temp;
    }
    playCard - playCard.getBuffer()[0];
    UnoCard* temp = new wildcardplus4();
    temp->setWarna(color);
    playCard + temp;
}

void UnoGameManager::putCard(UnoCard* card){
    // Menaruh kartu tipe Play ke playCard
    if (card->getCardType() == "Play"){
        // check if the card is valid, same color or same number with the top of playCard
        if (card->getType() == playCard.getBuffer()[0]->getType() || card->getNum() == playCard.getBuffer()[0]->getNum()){
            // erase the first element of playCard and push the card to the back of playCard
            lastInput = players->getPlayer(0).getName();
            playCard - playCard.getBuffer()[0];
            playCard + card;
            players->removePlayerCard(0, *card);
        }else{
            throw WrongCard();
        }
    }
    else if(card->getCardType() == "Plus2"){
        // check if the card is valid, same color or same number with the top of playCard
        if (card->getType() == playCard.getBuffer()[0]->getType() || card->getNum() == playCard.getBuffer()[0]->getNum()){
            lastInput = players->getPlayer(0).getName();
            playCard - playCard.getBuffer()[0];
            playCard + card;
            players->removePlayerCard(0, *card);
            manipulate<plus2&>(dynamic_cast<plus2&>(*card));
        }else{
            throw WrongCard();
        }
    }else if (card->getCardType() == "Reverse"){
        // check if the card is valid, same color or same number with the top of playCard
        if (card->getType() == playCard.getBuffer()[0]->getType() || card->getNum() == playCard.getBuffer()[0]->getNum()){
            lastInput = players->getPlayer(0).getName();
            playCard - playCard.getBuffer()[0];
            playCard + card;
            players->removePlayerCard(0, *card);
            manipulate<reversecard&>(dynamic_cast<reversecard&>(*card));
        }else{
            throw WrongCard();
        }
    }else if (card->getCardType() == "Skip"){
        // check if the card is valid, same color or same number with the top of playCard
        if (card->getType() == playCard.getBuffer()[0]->getType() || card->getNum() == playCard.getBuffer()[0]->getNum()){
            lastInput = players->getPlayer(0).getName();
            cout << "======== : " << lastInput << endl;
            playCard - playCard.getBuffer()[0];
            playCard + card;
            players->removePlayerCard(0, *card);
            manipulate<skip&>(dynamic_cast<skip&>(*card));
        }else{
            throw WrongCard();
        }
    }else if (card->getCardType() == "Wildcard"){
        lastInput = players->getPlayer(0).getName();
        manipulate<wildcard&>(dynamic_cast<wildcard&>(*card));
        players->removePlayerCard(0, *card);
    }else if (card->getCardType() == "Wildcard+4"){
        lastInput = players->getPlayer(0).getName();
        players->removePlayerCard(0, *card);
        manipulate<wildcardplus4&>(dynamic_cast<wildcardplus4&>(*card));
    }else{
        cout << "Kartu ERROR" << endl;
    }
}

bool UnoGameManager::isInputTrue(string aksi) const
{
    return aksi == "putcard" || aksi == "takecard" || aksi == "endturn";
}

bool UnoGameManager::parseCommand(string aksi){
    if(!isInputTrue(aksi))
    {
        throw WrongInput();
    }
    else
    {
        if(aksi == "putcard"){
            // milih kartu, lalu masuk ke putCard
            int cardIndex;
            cout << "Pilih kartu: ";
            cin >> cardIndex;
            if (cardIndex > players->getPlayer(0).getBuffer().size() || cardIndex < 1){
                throw CardIndexErr();
            }
            UnoCard* temp = players->getPlayer(0).getBuffer()[cardIndex-1];
            if (lastInput == players->getPlayer(0).getName()){
                if(temp->getNum() != playCard.getBuffer()[0]->getNum()){
                    throw DifferentType();
                }
            }
            putCard(temp);
            if(temp->getCardType() != "Wildcard" && temp->getCardType() != "Wildcard+4" && temp->getCardType() != "Plus2" && temp->getCardType() != "Skip" && temp->getCardType() != "Reverse"){
                players->getPlayerAddress(0)->setIsInputed(true);
                players->prevTurn();
            }
        }else if(aksi == "takecard"){
            // ambil 1 kartu dari deckCard
            lastInput = "";
            UnoCard* temp = deckCards.getCard(0);
            players->addPlayerCard(0, *temp);
            cout << "Mengambil kartu: ";
            temp->printInfo();
            cout << endl;
            deckCards - temp;
            cin.get();
            cout << "Press enter to continue...";
            cin.get();
        }else if(aksi == "endturn"){
            if(!players->getPlayerAddress(0)->isInputed){
                throw EndTurnErr();
            }else{
                players->getPlayerAddress(0)->setIsInputed(false);
            }
        }
        return true;
    }
}

bool UnoGameManager::isGameOver(){
    for (int i = 0 ; i < players->getSize(); i++){
        if (players->getPlayer(i).getCard().size() == 0){
            string name = players->getPlayer(i).getName();
            winner.push_back(name);
            players->removePlayer(i);
        }
    }

    if (players->getSize() == 1){
        string name = players->getPlayer(0).getName();
        winner.push_back(name);
        return true;
    }else{
        return false;
    }
}

void UnoGameManager::displayWinner() const{
    cout << "Permainan selesai!" << endl;
    cout << "Pemenang : " << endl;
    int j = 1;
    for (int i = winner.size()-1; i >= 0; i--){
        cout << j << ". " << winner[i] << endl;
        j++;
    }
}