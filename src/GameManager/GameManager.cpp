#include "GameManager.hpp"

GameManager::~GameManager(){ cout << "Thank You For Playing The Game!" << endl;}
GameManager::GameManager(){
    this->giliran = 0;

    players = new Player[7];
    /* Make Players */
    for(int i= 0; i < 7; i++){
        string name;
        cout << "Masukkan Nama Player "<< i+1 << ": "<< endl;
        cin >> name;

        players[i] = Player(name);
    }
    /* Berlanjut ... */
}
void GameManager::setGiliran(int g){this->giliran = 0;}
