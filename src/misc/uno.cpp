#include "CardCollection.hpp"

int main(){
    CardCollection<UnoCard*> cc;
    cc.MakeDeck();
    // cout << "WOI" << endl;
    cc.displayDeckCard();
    // cout << "BUFFER SIZE : " << cc.getBuffer().size() << endl;
    UnoCard* card = new UnoPlayCards(1, 1);
    cc + card;
    cc.displayDeckCard();
}

// g++ -o main main.cpp CardCollection.cpp UnoCard.cpp UnoPlayCards.cpp UnoActionCard.cpp Angka.cpp Warna.cpp DeckCard.cpp AbilityCard.cpp Abilities.cpp ../utils/printColor.cpp ../Exception/Exception.cpp