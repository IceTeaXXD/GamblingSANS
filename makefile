# Compiler & linker
C            = g++

# Directory
SOURCE_FOLDER = src
OUTPUT_FOLDER = bin

run: build
 $(OUTPUT_FOLDER)/a.exe

build:
 $(C) -c $(SOURCE_FOLDER)/Card/AbilityCard.cpp -o $(OUTPUT_FOLDER)/AbilityCard.o
 $(C) -c $(SOURCE_FOLDER)/Card/Warna.cpp -o $(OUTPUT_FOLDER)/Warna.o
 $(C) -c $(SOURCE_FOLDER)/Card/Angka.cpp -o $(OUTPUT_FOLDER)/Angka.o
 $(C) -c $(SOURCE_FOLDER)/Card/DeckCard.cpp -o $(OUTPUT_FOLDER)/DeckCard.o
 $(C) -c $(SOURCE_FOLDER)/Card/DeckCardCollection.cpp -o $(OUTPUT_FOLDER)/DeckCardCollection.o
 $(C) -c $(SOURCE_FOLDER)/GameManager/GameManager.cpp -o $(OUTPUT_FOLDER)/GameManager.o
 $(C) -c $(SOURCE_FOLDER)/Player/Player.cpp -o $(OUTPUT_FOLDER)/Player.o
 $(C) -c $(SOURCE_FOLDER)/Player/ArrOfPlayer.cpp -o $(OUTPUT_FOLDER)/ArrOfPlayer.o
 $(C) -c $(SOURCE_FOLDER)/Rules/FindValue.cpp -o $(OUTPUT_FOLDER)/FindValue.o
 $(C) -c $(SOURCE_FOLDER)/Rules/Kombinasi.cpp -o $(OUTPUT_FOLDER)/Kombinasi.o
 $(C) $(SOURCE_FOLDER)/main.cpp $(OUTPUT_FOLDER)/AbilityCard.o $(OUTPUT_FOLDER)/DeckCard.o $(OUTPUT_FOLDER)/GameManager.o $(OUTPUT_FOLDER)/Player.o $(OUTPUT_FOLDER)/ArrOfPlayer.o $(OUTPUT_FOLDER)/FindValue.o $(OUTPUT_FOLDER)/Kombinasi.o $(OUTPUT_FOLDER)/Warna.o $(OUTPUT_FOLDER)/Angka.o $(OUTPUT_FOLDER)/DeckCardCollection.o -o $(OUTPUT_FOLDER)/a.exe
 del $(OUTPUT_FOLDER)\*.o
 cls