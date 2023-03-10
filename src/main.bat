@REM g++ -c "./Card/AbilityCard.cpp" -o ../bin/AbilityCard.o
g++ -c "./Card/Warna.cpp" -o ../bin/Warna.o
g++ -c "./Card/Angka.cpp" -o ../bin/Angka.o
g++ -c "./Card/DeckCard.cpp" -o ../bin/DeckCard.o
@REM g++ -c "./Card/DeckCardCollection.cpp" -o ../bin/DeckCardCollection.o
g++ -c "./Card/CardCollection.cpp" -o ../bin/CardCollection.o
g++ -c "./GameManager/GameManager.cpp" -o ../bin/GameManager.o
g++ -c "./Player/Player.cpp" -o ../bin/Player.o
g++ -c "./Player/ArrOfPlayer.cpp" -o ../bin/ArrOfPlayer.o
g++ -c "./Rules/Kombinasi.cpp" -o ../bin/Kombinasi.o
g++ -c "./Rules/FindValue.cpp" -o ../bin/FindValue.o
g++ main.cpp ../bin/DeckCard.o ../bin/CardCollection.o ../bin/GameManager.o ../bin/Player.o ../bin/ArrOfPlayer.o ../bin/FindValue.o ../bin/Kombinasi.o ../bin/Warna.o ../bin/Angka.o
test&cls
a.exe