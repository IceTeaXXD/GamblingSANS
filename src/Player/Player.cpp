/* Filename: Player.cpp 
    Implementasi Kelas Player */
#include "Player.hpp"

int Player::countOfPlayers = 0;

Player::Player(){}

Player::Player(string nom):name(nom), point(0), countofPlayerCards(2), countofAbilityCards(7){ countOfPlayers++; this->id = countOfPlayers; }

Player::~Player(){ countOfPlayers--; }

string Player::getName(){
    return this->name;
}

int Player::getID(){
    return this->id;
}

int Player::getPoint(){
    return this->point;
}

void Player::setPoint(int p){
    this->point = p;
}