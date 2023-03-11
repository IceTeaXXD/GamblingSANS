g++ -c "Kombinasi.cpp" -o Kombinasi.o
g++ -c "FindValue.cpp" -o FindValue.o
g++ -c "../Card/DeckCard.cpp" -o DeckCard.o
g++ -c "../Card/CardCollection.cpp" -o CardCollection.o
g++ -c "../Card/Warna.cpp" -o Warna.o
g++ -c "../Card/Angka.cpp" -o Angka.o
g++ -c "../Card/Abilities.cpp" -o Abilities.o
g++ -c "../Card/AbilityCard.cpp" -o AbilityCard.o
g++ main.cpp AbilityCard.o DeckCard.o FindValue.o Kombinasi.o Warna.o Angka.o CardCollection.o Abilities.o
test&cls
a.exe