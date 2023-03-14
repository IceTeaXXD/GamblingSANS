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
            players->getPlayer(j) + deckCards.getCard(0);
            deckCards.getBuffer().erase(deckCards.getBuffer().begin());
            cout << deckCards.getBuffer().size() << endl;
        }
    }
}

template<>
void UnoGameManager::manipulate<plus2&>(plus2& card){
    //
}

template<>
void UnoGameManager::manipulate<reversecard&>(reversecard& card){
    players->reverseTurn(0);

}

template<>
void UnoGameManager::manipulate<skip&>(skip& card){
    players->nextTurn();
}

template<>
void UnoGameManager::manipulate<wildcard&>(wildcard& card){
    cout << "Pilih Warna: " << endl;
    pc.printRed("1. Hijau");
    cout << endl;
    pc.printBlue("2. Biru");
    cout << endl;
    pc.printGreen("3. Kuning");
    cout << endl;
    pc.printYellow("4. Merah");
    cout << endl;

    int color;
    cout << ">> ";
    cin >> color;
    card.setWarna(color);
}

template<>
void UnoGameManager::manipulate<wildcardplus4&>(wildcardplus4& card){

}

template<>
void UnoGameManager::manipulate<UnoCard*>(UnoCard* card){
    if (card->getCardType() == "Plus2"){
        manipulate<plus2&>(dynamic_cast<plus2&>(*card));
    }else if(card->getCardType() == "Wildcard"){
        manipulate<wildcard&>(dynamic_cast<wildcard&>(*card));
    }else if (card->getCardType() == "Reverse"){
        manipulate<reversecard&>(dynamic_cast<reversecard&>(*card));
    }else if (card->getCardType() == "Skip"){
        manipulate<skip&>(dynamic_cast<skip&>(*card));
    }else if (card->getCardType() == "Wildcard+4"){
        manipulate<wildcardplus4&>(dynamic_cast<wildcardplus4&>(*card));
    }
}   