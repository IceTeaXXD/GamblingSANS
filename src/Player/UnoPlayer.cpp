#include "UnoPlayer.hpp"

UnoGamePlayer::UnoGamePlayer() : Player(){
    this->countofPlayerCards = 0;
    this->isInputed = false;
}

UnoGamePlayer::UnoGamePlayer(string nom): countofPlayerCards(0), Player(nom){this->countofPlayerCards = 0; this->isInputed = false;}

UnoGamePlayer::~UnoGamePlayer(){}

void UnoGamePlayer::operator+(UnoCard* cardInput){
    CardCollection<UnoCard*>::operator+(cardInput);
    this->countofPlayerCards++;
}

void UnoGamePlayer::viewAllCard(){
    // cout << "Player " << this->getName() << " has " << this->countofPlayerCards << " cards" << endl;
    cout << "Player " << this->getName() << " cards : " << endl;
    for (int i = 0; i < this->countofPlayerCards; i++){
        cout << i+1 << ". ";
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
    buffer.push_back(&cardInput);
    this->countofPlayerCards++;
}

void UnoGamePlayer::operator-(UnoCard& cardInput){
    for (int i = 0; i < this->countofPlayerCards; i++){
        if (this->getCard()[i] == &cardInput){
            buffer.erase(buffer.begin() + i);
            this->countofPlayerCards--;
            break;
        }
    }
}

void UnoGamePlayer::setIsInputed(bool fuck)
{
    this->isInputed = fuck;
}