# Compiler & linker
C             = g++

# Directory
SOURCE_FOLDER = src
OUTPUT_FOLDER = bin

run: build
	$(OUTPUT_FOLDER)/main.exe

build:
	$(C) -c $(SOURCE_FOLDER)/Card/AbilityCard.cpp -o $(OUTPUT_FOLDER)/AbilityCard.o
	$(C) -c $(SOURCE_FOLDER)/Card/Abilities.cpp -o $(OUTPUT_FOLDER)/Abilities.o
	$(C) -c $(SOURCE_FOLDER)/Card/Warna.cpp -o $(OUTPUT_FOLDER)/Warna.o
	$(C) -c $(SOURCE_FOLDER)/Card/Angka.cpp -o $(OUTPUT_FOLDER)/Angka.o
	$(C) -c $(SOURCE_FOLDER)/Card/CardCollection.cpp -o $(OUTPUT_FOLDER)/CardCollection.o
	$(C) -c $(SOURCE_FOLDER)/Card/DeckCard.cpp -o $(OUTPUT_FOLDER)/DeckCard.o
	$(C) -c $(SOURCE_FOLDER)/GameManager/GameManager.cpp -o $(OUTPUT_FOLDER)/GameManager.o
	$(C) -c $(SOURCE_FOLDER)/GameManager/CandyGameManager.cpp -o $(OUTPUT_FOLDER)/CandyGameManager.o
	$(C) -c $(SOURCE_FOLDER)/GameManager/CapchaManager.cpp -o $(OUTPUT_FOLDER)/CapchaManager.o
	$(C) -c $(SOURCE_FOLDER)/Player/Player.cpp -o $(OUTPUT_FOLDER)/Player.o
	$(C) -c $(SOURCE_FOLDER)/Player/ArrOfPlayer.cpp -o $(OUTPUT_FOLDER)/ArrOfPlayer.o
	$(C) -c $(SOURCE_FOLDER)/Rules/Kombinasi.cpp -o $(OUTPUT_FOLDER)/Kombinasi.o
	$(C) -c $(SOURCE_FOLDER)/Rules/FindValue.cpp -o $(OUTPUT_FOLDER)/FindValue.o	
	$(C) $(SOURCE_FOLDER)/main.cpp $(OUTPUT_FOLDER)/*.o -o $(OUTPUT_FOLDER)/main.exe
	@rm $(OUTPUT_FOLDER)/*.o

# g++ -o bin/main src/main.cpp src/Card/AbilityCard.cpp src/Card/Warna.cpp src/Card/Angka.cpp src/Card/DeckCard.cpp src/Card/DeckCardCollection.cpp src/GameManager/GameManager.cpp src/Player/Player.cpp src/Player/ArrOfPlayer.cpp src/Rules/Kombinasi.cpp src/Rules/FindValue.cpp