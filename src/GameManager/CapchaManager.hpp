#ifndef CAPCHA_MANAGER_HPP
#define CAPCHA_MANAGER_HPP

#include <iostream>
#include <stack>
#include <deque>
#include "../Card/Angka.hpp"
#include "../Player/Player.hpp"
#include "../Player/ArrOfPlayer.hpp"
#include "../Rules/Kombinasi.hpp"

using namespace std;

class CapchaManager{
    private:
        ArrOfPlayer players;
    public:
        CapchaManager();
        ~CapchaManager();

        void startGame();
        void printInfo();
        void printInfoPlayer();
        void printInfoPlayerCard(int); //buat ngecek player punya kartu apa aja

        void setGiliran(int);
        int getGiliran();
        void setPoint(int);
};

#endif