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
    players->reverseTurn(0);
    players->prevTurn();
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
    cout << "TIPE KARTU : " << card->getCardType() << endl;
    // Menaruh kartu tipe Play ke playCard
    if (card->getCardType() == "Play"){
        // check if the card is valid, same color or same number with the top of playCard
        if (card->getType() == playCard.getBuffer()[0]->getType() || card->getNum() == playCard.getBuffer()[0]->getNum()){
            // erase the first element of playCard and push the card to the back of playCard
            playCard - playCard.getBuffer()[0];
            playCard + card;
            players->removePlayerCard(0, *card);
        }else{
            cout << "Kartu tidak valid" << endl;
        }
    }
    else if(card->getCardType() == "Plus2"){
        // check if the card is valid, same color or same number with the top of playCard
        if (card->getType() == playCard.getBuffer()[0]->getType() || card->getNum() == playCard.getBuffer()[0]->getNum()){
            playCard - playCard.getBuffer()[0];
            playCard + card;
            manipulate<plus2&>(dynamic_cast<plus2&>(*card));
            players->removePlayerCard(0, *card);
        }else{
            cout << "Kartu tidak valid" << endl;
        }
    }else if (card->getCardType() == "Reverse"){
        // check if the card is valid, same color or same number with the top of playCard
        if (card->getType() == playCard.getBuffer()[0]->getType() || card->getNum() == playCard.getBuffer()[0]->getNum()){
            playCard - playCard.getBuffer()[0];
            playCard + card;
            manipulate<reversecard&>(dynamic_cast<reversecard&>(*card));
            players->removePlayerCard(0, *card);
        }else{
            cout << "Kartu tidak valid" << endl;
        }
    }else if (card->getCardType() == "Skip"){
        // check if the card is valid, same color or same number with the top of playCard
        if (card->getType() == playCard.getBuffer()[0]->getType() || card->getNum() == playCard.getBuffer()[0]->getNum()){
            playCard - playCard.getBuffer()[0];
            playCard + card;
            manipulate<skip&>(dynamic_cast<skip&>(*card));
            players->removePlayerCard(0, *card);
        }else{
            cout << "Kartu tidak valid" << endl;
        }
    }else if (card->getCardType() == "Wildcard"){
        manipulate<wildcard&>(dynamic_cast<wildcard&>(*card));
        players->removePlayerCard(0, *card);
    }else if (card->getCardType() == "Wildcard+4"){
        manipulate<wildcardplus4&>(dynamic_cast<wildcardplus4&>(*card));
        players->removePlayerCard(0, *card);
    }else{
        cout << "Kartu ERROR" << endl;
    }
}

bool UnoGameManager::isInputTrue(string aksi) const
{
    return aksi == "inputcard" || aksi == "addcard" || aksi == "endturn";
}

bool UnoGameManager::parseCommand(string aksi){
    if(!isInputTrue(aksi))
    {
        throw InputSalah();
    }
    else
    {
        if(aksi == "inputcard"){
            // milih kartu, lalu masuk ke putCard
            int cardIndex;
            cout << "Pilih kartu: ";
            cin >> cardIndex;
            UnoCard* temp = players->getPlayer(0).getBuffer()[cardIndex-1];
            if (lastInput == players->getPlayer(0).getName()){
                // cek kartu yg dipilih, angkanya harus sama!
            }
            putCard(temp);
            if(temp->getCardType() != "Wildcard" && temp->getCardType() != "Wildcard+4"){
                players->getPlayerAddress(0)->setIsInputed();
                players->prevTurn();
            }
            lastInput = players->getPlayer(0).getName();
        }else if(aksi == "addcard"){
            // ambil 1 kartu dari deckCard
            UnoCard* temp = deckCards.getCard(0);
            players->addPlayerCard(0, *temp);
            cout << "Mengambil kartu: ";
            temp->printInfo();
            cout << endl;
            deckCards - temp;
        }else if(aksi == "endturn"){
            if(!players->getPlayerAddress(0)->isInputed){
                throw EndTurnErr();
            }else{
                players->getPlayerAddress(0)->setIsInputed();
            }
        }
        return true;
    }
}

bool UnoGameManager::isGameOver() const{
    int count = 0;
    for(int i = 0; i < 4; i++)
    {
        if(players->getPlayer(i).getCard().size() == 0)
        {
            count++;
        }
    }
    if(count == 3)
    {
        return true;
    }else{
        return false;
    }
}

void UnoGameManager::displayWinner() const{
    for(int i = 0; i < 4; i++)
    {
        if(players->getPlayer(i).getCard().size() == 0)
        {
            cout << "Pemain " << players->getPlayer(i).getName() << " sudah menang" << endl;
            break;
        }
    }
}