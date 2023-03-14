#include "UnoPlayer.hpp"

UnoGamePlayer::UnoGamePlayer() : Player(){
    this->countofPlayerCards = 0;
}

UnoGamePlayer::UnoGamePlayer(string nom): countofPlayerCards(0), Player(nom){}

UnoGamePlayer::~UnoGamePlayer(){}

void UnoGamePlayer::operator+(UnoCard* cardInput){
    CardCollection<UnoCard*>::operator+(cardInput);
    this->countofPlayerCards++;
}

void UnoGamePlayer::viewAllCard(){
    cout << "Player " << this->getName() << " has " << this->countofPlayerCards << " cards" << endl;
    for (int i = 0; i < this->countofPlayerCards; i++){
        this->getCard()[i]->printInfo();
        cout << endl;
    }
}

vector<UnoCard*> UnoGamePlayer::getCard(){
    return CardCollection<UnoCard*>::buffer;
}

void UnoGamePlayer::clearCards(){
    CardCollection<UnoCard*>::clear();
    this->countofPlayerCards = 0;
}

void UnoGamePlayer::operator+(UnoCard& cardInput){
    UnoCard* card = new UnoCard(cardInput);
    CardCollection<UnoCard*>::operator+(card);
    this->countofPlayerCards++;
}