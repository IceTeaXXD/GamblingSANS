g++ -c "./Card/AbilityCard.cpp" -o ../bin/AbilityCard.o
g++ -c "./Card/Warna.cpp" -o ../bin/Warna.o
g++ -c "./Card/Angka.cpp" -o ../bin/Angka.o
g++ -c "./Card/DeckCard.cpp" -o ../bin/DeckCard.o
g++ -c "./Card/DeckCardCollection.cpp" -o ../bin/DeckCardCollection.o
g++ -c "./GameManager/GameManager.cpp" -o ../bin/GameManager.o
g++ -c "./Player/Player.cpp" -o ../bin/Player.o
g++ -c "./Player/ArrOfPlayer.cpp" -o ../bin/ArrOfPlayer.o
g++ -c "./Rules/Kombinasi.cpp" -o ../bin/Kombinasi.o
g++ main.cpp ../bin/AbilityCard.o ../bin/DeckCard.o ../bin/GameManager.o ../bin/Player.o ../bin/ArrOfPlayer.o ../bin/FindValue.o ../bin/Kombinasi.o ../bin/Warna.o ../bin/Angka.o ../bin/DeckCardCollection.o
test&cls
a.exe