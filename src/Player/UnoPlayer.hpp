#include "Player.hpp"
#include "../Card/UnoCard.hpp"
#include "../Card/UnoPlayCards.hpp"
#include "../Card/UnoActionCard.hpp"

class UnoGamePlayer : public Player, public CardCollection<UnoCard*>{
    public:
        UnoGamePlayer();
        UnoGamePlayer(string);
        ~UnoGamePlayer();
        int countofPlayerCards;
        void operator+(UnoCard*);
        void viewAllCard();
        vector<UnoCard*> getCard();
        void clearCards();
        void operator+(UnoCard&);
        void operator-(UnoCard&);
        bool isInputed;
        void setIsInputed(bool);

};