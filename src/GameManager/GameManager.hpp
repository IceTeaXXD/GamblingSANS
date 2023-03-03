#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include "../Player/Player.hpp"
#include "../Player/ArrOfPlayer.hpp"
#include "../Card/DeckCard.hpp"
#include "../Card/DeckCardCollection.hpp"

#include <iostream>
using namespace std;
/*
    yang tinggal diimplementasi sejauh ini :
    1. getabilitycard
    2. distribute table card
    kalau udh nanti tambahin di bagian startgame()
    3. arah giliran masih statik -> harusnya berubah setiap ronde
    4. fungsi use() di ability card mungkin udh bisa diimplementasi juga
    5. Implementasi queue buat nentuin giliran permainan (biar lebih gampang klo ada yang make reverse)
    6. Implementasi poin dan aksi (next, double, half)
*/
class GameManager{
    private:
    public:
        /* Vector of Players */
        ArrOfPlayer players;
        /* Card Deck */
        DeckCardCollection tableCards;
        /* Play Cards */
        DeckCardCollection playCards;

        // AbilityCard* abilityCardList;
        static int numOfTableCards;
        long long point;

        /* Game Round */
        static int round;

        /* Inisiator Game */
        GameManager();
        ~GameManager();

        /* Mengubah Giliran dan Mendapatkan Giliran */
        void setGiliran(int);
        int getGiliran();
        /* Mengubah Point */
        void setPoint(long long);

        // void startGame();
        void displayPlayer();
        void initDistribute(int);
        DeckCard* getCard();
        // AbilityCard* getAbilityCard();
        void distributeTableCard();
};

#endif