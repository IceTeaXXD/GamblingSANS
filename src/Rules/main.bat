g++ -c "Kombinasi.cpp" -o Kombinasi.o
g++ -c "FindValue.cpp" -o FindValue.o
g++ -c "../Card/DeckCard.cpp" -o DeckCard.o
g++ -c "../Card/CardCollection.cpp" -o CardCollection.o
g++ -c "../Card/Warna.cpp" -o Warna.o
g++ -c "../Card/Angka.cpp" -o Angka.o
g++ main.cpp DeckCard.o FindValue.o Kombinasi.o Warna.o Angka.o CardCollection.o
test&cls
a.exe