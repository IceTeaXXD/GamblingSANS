g++ -c "./Card/AbilityCard.cpp" -o AbilityCard.o
g++ -c "./Card/DeckCard.cpp" -o DeckCard.o
g++ -c "./GameManager/GameManager.cpp" -o GameManager.o
g++ -c "./Player/Player.cpp" -o Player.o
g++ -c "./Player/ArrOfPlayer.cpp" -o ArrOfPlayer.o
g++ -c "./Rules/FindValue.cpp" -o FindValue.o
g++ -c "./Rules/Kombinasi.cpp" -o Kombinasi.o
g++ main.cpp AbilityCard.o DeckCard.o GameManager.o Player.o ArrOfPlayer.o FindValue.o Kombinasi.o
a.exe