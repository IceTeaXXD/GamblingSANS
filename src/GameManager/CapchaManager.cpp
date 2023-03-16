#include "CapchaManager.hpp"

CapchaManager::CapchaManager()
{
    // this->players = ArrOfPlayer(4);
    players = new ArrOfPlayer<CapsaGamePlayer>(4);
}

CapchaManager::~CapchaManager()
{
    cout<<"Thank You For Playing The Game!"<<endl;
}
void CapchaManager::setGiliran(int giliran)
{
    for (int i = 0; i < 4; i++)
    {
        srand(time(NULL));
        int random = rand() % 4;
        this->giliran = random;
    }
}
ArrOfPlayer<CapsaGamePlayer>& CapchaManager::getPlayers()
{
    return *players;
}

CardCollection<DeckCard>* CapchaManager::getCards()
{
    return &this->Cards;
}

bool CapchaManager::parseCommand(string aksi){
    
    return true;
}

void CapchaManager::parserFirstPlayer(string aksi, deque<CapsaGamePlayer*>& pointerArr, bool& menang, bool& flag, int& angka){
    while (aksi!="HighCard"&&aksi!="Pair"&&aksi!="TwoPair"&&\
        aksi!="ThreeAKind"&&aksi!="Straight"&&aksi!="Flush"&&\
        aksi!="FullHouse"&&aksi!="FourAKind"&&aksi!="StraightFlush")
    {
    cout << "Input salah. Ketik nama kombinasi seperti pada layar tanpa spasi.\n";
    cout<<">> ";
    cin >> aksi;
    }
    pointerArr[0]->getArrOfKombinasi()->displaySpecificCombination(aksi);
    cout<<"Masukkan nomor kombinasi yang ingin dikeluarkan : "<<endl;
    cout<<">> ";
    cin>>angka;
    while(angka > pointerArr[0]->getArrOfKombinasi()->dropCombSize() || angka <= 0)
    {
        cout<<"Masukkan nomor kombinasi yang ingin dikeluarkan : "<<endl;
        cout<<">> ";
        cin>>angka;
    }
    this->setDroppedCombination(pointerArr[0]->getArrOfKombinasi()->DropCombination(angka-1));
    // cout<<this->getDroppedCombination().getCName()<<endl;
    *pointerArr[0]-this->getDroppedCombination();
    pointerArr[0]->setArrCombination();
    // this->getDroppedCombination().printKombinasi();
    this->setLastPlayed(this->getDroppedCombination());
    // newArrKombinasi.displaySpecificCombination("HighCard");
    flag = false;
    // cout<<pointerArr[0]->getCountOfPlayerCards()<<" JUMLAH KARTU"<<endl;
    if(pointerArr[0]->getCountOfPlayerCards() == 0)
    {
        menang = true;
        cout<<"Player "<<pointerArr[0]->getName()<<" telah memenangkan pertandingan"<<endl;
    }
}

void CapchaManager::parserNextPlayer(deque<CapsaGamePlayer*>& pointerArr, deque<CapsaGamePlayer*>& gamePlayer, bool& menang, int& angka){
    if (angka == 0)
    {
        gamePlayer.push_front(pointerArr.at(0));
        pointerArr.pop_front();
        cout<<"Anda melakukan PASS"<<endl;
    }
    else
    {
        // cout<<"P1"<<endl;
        // tempArrKombinasi = ArrOfKombinasi(pointerArr[0]->getCard());
        this->setDroppedCombination(pointerArr[0]->getGreaterComb(angka-1));
        // cout<<"CEK 1"<<endl;
        // cout<<"INI YANG DI GAME SETELAH UPDATE"<<endl;
        // this->getDroppedCombination().printKombinasi();
        *pointerArr[0]-(this->getDroppedCombination());
        pointerArr[0]->setArrCombination();
        cout<<pointerArr[0]->getCountOfPlayerCards()<<" JUMLAH KARTU"<<endl;
        // cout<<"CEK 2"<<endl;
        // cout<<"INI YANG DI GAME SETELAH UPDATE"<<endl;
        // this->getDroppedCombination().printKombinasi();
        // cout<<pointerArr[0]->getCountOfPlayerCards()<<endl;
        this->setLastPlayed(this->getDroppedCombination());
        // cout<<"CEK 3"<<endl;
        // cout<<"INI YANG DI GAME SETELAH UPDATE"<<endl;
        // this->getDroppedCombination().printKombinasi();
        if(pointerArr[0]->getCountOfPlayerCards() == 0)
        {
            menang = true;
            cout<<"Player "<<pointerArr[0]->getName()<<" telah memenangkan pertandingan"<<endl;
            cout<<"----------------------------SELAMAT---------------------------------"<<endl;
        }
        pointerArr.push_back(pointerArr.at(0));
        pointerArr.pop_front();
    }
}

int CapchaManager::firstPlayer(){
    vector<DeckCard> temp;
    vector<int> angka;
    for (int i = 0; i < 4; i++)
    {
        vector<DeckCard> buffer = players->getPlayer(i).getBuffer();
        temp.insert(temp.end(), buffer.begin(), buffer.end());
        buffer.clear();
    }
    for (int i = 0; i < temp.size(); i++)
    {
        angka.push_back(temp[i].getNum());
    }
    auto itr = find(angka.begin(), angka.end(), 3);
    while (temp[itr-angka.begin()].getType() != 4)
    {
       itr = find(itr+1, angka.end(), 3);
    }
    return (itr-angka.begin())/13;
}

Kombinasi CapchaManager::getLastPlayed(){
    return *lastPlayed;
}

void CapchaManager::setLastPlayed(Kombinasi& lastPlayed){
    this->lastPlayed = &lastPlayed;
}

void CapchaManager::clearLastPlayed(){
    delete this->lastPlayed;
}
void CapchaManager::setDroppedCombination(KombinasiCapsa c)
{
    this->droppedCombination.operator=(c);
}
KombinasiCapsa& CapchaManager::getDroppedCombination()
{
    return this->droppedCombination;
}
void CapchaManager::deleteAll3Cards()
{
    for (int i = 0; i < players[0].getSize(); i++)
    {
        CapsaGamePlayer* player = players[0].getPlayerAddress(i);
        player->delete3Cards();
    }
}
bool CapchaManager::isInputTrue(string) const
{
    return true;
}