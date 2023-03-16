g++ -c "Kombinasi.cpp" -o Kombinasi.o
g++ -c "FindValue.cpp" -o FindValue.o
g++ -c "../Card/DeckCard.cpp" -o DeckCard.o
g++ -c "../Card/CardCollection.cpp" -o CardCollection.o
g++ -c "../Card/Warna.cpp" -o Warna.o
g++ -c "../Card/Angka.cpp" -o Angka.o
g++ -c "../Card/Abilities.cpp" -o Abilities.o
g++ -c "../Card/AbilityCard.cpp" -o AbilityCard.o
g++ -c "../Card/UnoPlayCards.cpp" -o UnoPlayCards.o
g++ -c "../Card/UnoCard.cpp" -o UnoCard.o
g++ -c "../Card/UnoActionCard.cpp" -o UnoActionCard.o
g++ -c "../utils/printColor.cpp" -o printColor.o
g++ -c "../Exception/Exception.cpp" -o Exception.o
g++  main.cpp Exception.o AbilityCard.o DeckCard.o FindValue.o Kombinasi.o Warna.o Angka.o CardCollection.o Abilities.o UnoActionCard.o UnoPlayCards.o printColor.o UnoCard.o
test&cls
a.exe