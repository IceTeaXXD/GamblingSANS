#include "DeckCardCollection.hpp"
using namespace std;

DeckCardCollection::DeckCardCollection(){}

void DeckCardCollection::MakeDeck(){
    vector<DeckCard> cards;
        for (int i = 0 ; i<4 ; i++)
        {
            for (int j = 0 ; j < 13; j++)
            {
                DeckCard* c = new DeckCard(i+1,j+1);
                cards.push_back(*c);
            }
        }

        /* Mengacak */
        srand(time(0));
        vector<int> num;
        for (int i = 1; i <= 52; i++){
            num.push_back(i);
        }
        for (int i = 0; i < 52; i++){
            int randIdx = rand() % (52 - i);
            this->buffer.push_back(cards[num[randIdx]-1]);
            num.erase(num.begin() + randIdx);
        }
}

void DeckCardCollection::MakeDeck(string filename){
    /* 
        FORMAT FILE 
        n # Jumlah Kartu
        w1 a1 # Warna kartu 1, Angka 1
        w2 a2 # Warna kartu 2, Angka 2

        Angka dari 1-10, A, K, Q, J
    */

    string out;

    ifstream File(filename);

    /* Compute number of cards */
    getline(File, out);
    int n = stoi(out);

    for(int i = 0; i < n ; i++){
        getline(File, out);
        int count = 0;
        int w,a;
        for (auto x : out){
            if(x == ' '){
                /* PASS */
            }else{
                count += 1;
                if(count == 1){
                    w = x - '0';
                }else{
                    if(x == 'A'){
                        a = 10;
                    }else if(x=='K'){
                        a = 11;
                    }else if (x == 'Q'){
                        a = 12;
                    }else if(x == 'J'){
                        a = 13;
                    }else{
                        a = x - '0';
                    }
                }
            }
        }

        if(w > 0 && w <= 4 && a > 0 && a <= 13){
            buffer.push_back(DeckCard(w,a));
        }else{
            throw "Salah format. Perhatikan warna dan angka yang dimasukkan!\n";
        }
    }

    File.close();
}


DeckCardCollection::~DeckCardCollection(){}

DeckCard DeckCardCollection::getCard(int a){
    return(this->buffer[a]);
}

void DeckCardCollection::setCard(DeckCard& c){
    this->buffer.push_back(c);
}

DeckCard DeckCardCollection::takeCard(){
    DeckCard c = DeckCard(this->buffer[0]);
    this->buffer.erase(this->buffer.begin());
    // cout<<"Kamu dapat kartu "<<c->getNum()<<" "<<c->getType()<<endl;
    //Get Type perlu dibikin supaya per warnanya yang keluar bukan angka
    return c;
}

void DeckCardCollection::operator+(DeckCard& c){
    this->buffer.push_back(c);
}
void DeckCardCollection::displayDeckCard()
{
    for (auto it = buffer.begin(); it != buffer.end(); it++) 
    {
        it->printInfo();
    }
}

void DeckCardCollection::clear(){
    this->buffer.clear();
}