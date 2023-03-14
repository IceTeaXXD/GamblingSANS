#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include "../Player/Player.hpp"
#include "../Player/ArrOfPlayer.hpp"
#include "../Card/DeckCard.hpp"
#include "../Card/CardCollection.hpp"
#include "../Card/Abilities.hpp"
#include "../Card/AbilityCard.hpp"

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
class GameManager: public CardCollection<DeckCard>{
    protected:
        int round;
        int turn;
        // /* Card Deck */
        // CardCollection<DeckCard> tableCards;
        static int numOfTableCards;
        long long point;
    public:        
        /* Game Round */
        void setRound(int);
        int getRound();
        /* Game Turn */
        void setTurn(int);
        int getTurn();
        /* Inisiator Game */
        GameManager();
        GameManager(int);
        /* Bikin deck card dari file */
        GameManager(string);
        ~GameManager();

        /* Mengubah Point */
        void setPoint(long long);
        long long getPoint();
        DeckCard gameManager;
        vector<DeckCard>& getTableCards();
        virtual void displayPlayer();
        DeckCard* getCard();
        bool isInputTrue(string);

        void makeTableCards();
        void makeTableCards(string);

        /* Manipulasi */

        string inputToLower(string);
        virtual bool parseCommand(string) = 0;
};

#endif