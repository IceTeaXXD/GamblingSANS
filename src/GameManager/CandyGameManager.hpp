#ifndef CANDY_GAME_MANAGER_HPP
#define CANDY_GAME_MANAGER_HPP
#include "GameManager.hpp"
#include "../Player/Player.hpp"
#include "../Player/ArrOfPlayer.hpp"
#include "../Card/DeckCard.hpp"
#include "../Card/CardCollection.hpp"
#include "../Card/Abilities.hpp"
#include "../Card/AbilityCard.hpp"

class CandyGameManager : public GameManager
{
    private:
        /* Vector of Players */
        ArrOfPlayer<CandyGamePlayer>* players;
        /* Kartu yang di meja */
        CardCollection<DeckCard> playCards;
        /* List of Ability Cards */
        CardCollection<AbilityCard*> abilityCardList;
        
        
    public:
        CandyGameManager();
        CandyGameManager(string);
        CardCollection<DeckCard>& getPlayCards();
        CardCollection<AbilityCard*>& getAbilityCardList();

        void makeAbilityCards();

        void leaderboard();
        bool existWinner();
        void reset();

        ArrOfPlayer<CandyGamePlayer>& getPlayers();
        void displayPlayer();

        /*Manipulasi*/
        template<class T>
        void manipulate(T);
};
#endif