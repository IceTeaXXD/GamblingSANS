#include "DeckCardCollection.hpp"

int main(){
    DeckCardCollection arr;
    try{
    arr.MakeDeck("test.txt");
    
    arr.displayDeckCard();
    }catch (char const* e){
        cout << e << endl;
        arr.clear();
    }
    return 0;
}