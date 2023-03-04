#include <iostream>
#include "Kombinasi.hpp"

int main()
{
    DeckCardCollection table;
    DeckCardCollection p1;
    DeckCardCollection p2;
    DeckCardCollection p3;
    DeckCardCollection p4;
    DeckCardCollection p5;
    DeckCardCollection p6;
    DeckCardCollection p7;

    //table card
    DeckCard k4 = DeckCard(2,4);
    DeckCard k2 = DeckCard(2,2);
    DeckCard b7 = DeckCard(3,7);
    DeckCard b11 = DeckCard(3,11);
    DeckCard h13 = DeckCard(1,13);

    //pair - 1
    DeckCard m1 = DeckCard(4,1);
    DeckCard k1 = DeckCard(3,1);

    //three of kind - 2
    DeckCard m2 = DeckCard(4,2);
    DeckCard b2 = DeckCard(3,1);

    //HighCard - 3
    DeckCard h1 = DeckCard(1,1);
    DeckCard h4 = DeckCard(1,4);

    //HighCard - 4
    DeckCard h2 =DeckCard(1,2);
    DeckCard h3 = DeckCard(1,3);

    //HighCard - 5
    DeckCard b4 = DeckCard(3,4);
    DeckCard b3 = DeckCard(3,2);

    //HighCard - 6
    DeckCard k6 = DeckCard(2,6);
    DeckCard k8 = DeckCard(2,8);

    //HighCard - 7
    DeckCard h8  = DeckCard(1,8);
    DeckCard h9 = DeckCard(1,9);

    table.addCard(k4);
    table.addCard(k2);
    table.addCard(b7);
    table.addCard(b11);
    table.addCard(h13);

    p1.addCard(m1);
    p1.addCard(k1);

    p2.addCard(m2);
    p2.addCard(b2);

    p3.addCard(h1);
    p3.addCard(h4);

    p4.addCard(h2);
    p4.addCard(h3);

    p5.addCard(b4);
    p5.addCard(b3);

    p6.addCard(k6);
    p6.addCard(k8);

    p7.addCard(h8);
    p7.addCard(h9);

    //KOMBINASI
    Kombinasi c1 = Kombinasi(p1,table);
    cout<<c1.getCombinationName()<<endl;
    cout<<c1.value()<<endl;
}