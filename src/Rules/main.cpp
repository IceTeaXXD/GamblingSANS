#include <iostream>
#include "Kombinasi.hpp"

int main()
{
    CardCollection<DeckCard> table;
    CardCollection<DeckCard> p1;
    CardCollection<DeckCard> p2;
    CardCollection<DeckCard> p3;
    CardCollection<DeckCard> p4;
    CardCollection<DeckCard> p5;
    CardCollection<DeckCard> p6;
    CardCollection<DeckCard> p7;

    //table card
    // DeckCard k4 = DeckCard(2,4);
    // DeckCard k2 = DeckCard(2,2);
    // DeckCard b7 = DeckCard(3,7);
    // DeckCard b11 = DeckCard(3,11);
    // DeckCard h13 = DeckCard(1,13);

    //HighCard - 7
    DeckCard h1 = DeckCard(1,1);
    DeckCard h2 = DeckCard(1,2);
    DeckCard h3 = DeckCard(1,3);
    DeckCard h4 = DeckCard(1,4);
    DeckCard h5 = DeckCard(1,5);
    DeckCard h6 = DeckCard(1,6);
    DeckCard h7 = DeckCard(1,7);
    DeckCard h8  = DeckCard(1,8);
    DeckCard h9 = DeckCard(1,9);
    DeckCard h10 = DeckCard(1,10);
    DeckCard h11 = DeckCard(1,11);
    DeckCard h12 = DeckCard(1,12);
    DeckCard h13 = DeckCard(1,13);

    DeckCard m1 = DeckCard(4,1);
    DeckCard m2 = DeckCard(4,2);
    DeckCard m3 = DeckCard(4,3);
    DeckCard m4 = DeckCard(4,4);
    DeckCard m5 = DeckCard(4,5);
    DeckCard m6 = DeckCard(4,6);
    DeckCard m7 = DeckCard(4,7);
    DeckCard m8  = DeckCard(4,8);
    DeckCard m9 = DeckCard(4,9);
    DeckCard m10 = DeckCard(4,10);
    DeckCard m11 = DeckCard(4,11);
    DeckCard m12 = DeckCard(4,12);
    DeckCard m13 = DeckCard(4,13);
    
    DeckCard b1 = DeckCard(3,1);
    DeckCard b2 = DeckCard(3,2);
    DeckCard b3 = DeckCard(3,3);
    DeckCard b4 = DeckCard(3,4);
    DeckCard b5 = DeckCard(3,5);
    DeckCard b6 = DeckCard(3,6);
    DeckCard b7 = DeckCard(3,7);
    DeckCard b8  = DeckCard(3,8);
    DeckCard b9 = DeckCard(3,9);
    DeckCard b10 = DeckCard(3,10);
    DeckCard b11 = DeckCard(3,11);
    DeckCard b12 = DeckCard(3,12);
    DeckCard b13 = DeckCard(3,13);

    DeckCard k1 = DeckCard(2,1);
    DeckCard k2 = DeckCard(2,2);
    DeckCard k3 = DeckCard(2,3);
    DeckCard k4 = DeckCard(2,4);
    DeckCard k5 = DeckCard(2,5);
    DeckCard k6 = DeckCard(2,6);
    DeckCard k7 = DeckCard(2,7);
    DeckCard k8  = DeckCard(2,8);
    DeckCard k9 = DeckCard(2,9);
    DeckCard k10 = DeckCard(2,10);
    DeckCard k11 = DeckCard(2,11);
    DeckCard k12 = DeckCard(2,12);
    DeckCard k13 = DeckCard(2,13);
    table.addCard(m1);
    table.addCard(m2);
    table.addCard(k3);
    table.addCard(m4);
    table.addCard(h5);

    p1.addCard(m1);
    p1.addCard(m7);

    p2.addCard(b3);
    p2.addCard(m7);

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
    Kombinasi c1 = Kombinasi(p2,table);
    cout<<c1.getCombinationName()<<endl;
    cout<<c1.value()<<endl;
}