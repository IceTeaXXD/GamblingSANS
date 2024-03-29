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
	$(C) -c $(SOURCE_FOLDER)/Card/UnoCard.cpp -o $(OUTPUT_FOLDER)/UnoCard.o
	$(C) -c $(SOURCE_FOLDER)/Card/UnoPlayCards.cpp -o $(OUTPUT_FOLDER)/UnoPlayCards.o
	$(C) -c $(SOURCE_FOLDER)/Card/UnoActionCard.cpp -o $(OUTPUT_FOLDER)/UnoActionCard.o
	$(C) -c $(SOURCE_FOLDER)/GameManager/GameManager.cpp -o $(OUTPUT_FOLDER)/GameManager.o
	$(C) -c $(SOURCE_FOLDER)/GameManager/CandyGameManager.cpp -o $(OUTPUT_FOLDER)/CandyGameManager.o
	$(C) -c $(SOURCE_FOLDER)/GameManager/CapchaManager.cpp -o $(OUTPUT_FOLDER)/CapchaManager.o
	$(C) -c $(SOURCE_FOLDER)/GameManager/UnoGameManager.cpp -o $(OUTPUT_FOLDER)/UnoGameManager.o
	$(C) -c $(SOURCE_FOLDER)/Player/Player.cpp -o $(OUTPUT_FOLDER)/Player.o
	$(C) -c $(SOURCE_FOLDER)/Player/ArrOfPlayer.cpp -o $(OUTPUT_FOLDER)/ArrOfPlayer.o
	$(C) -c $(SOURCE_FOLDER)/Player/UnoPlayer.cpp -o $(OUTPUT_FOLDER)/UnoPlayer.o
	$(C) -c $(SOURCE_FOLDER)/Exception/Exception.cpp -o $(OUTPUT_FOLDER)/Exception.o
	$(C) -c $(SOURCE_FOLDER)/Rules/Kombinasi.cpp -o $(OUTPUT_FOLDER)/Kombinasi.o
	$(C) -c $(SOURCE_FOLDER)/Rules/KombinasiCapsa.cpp -o $(OUTPUT_FOLDER)/KombinasiCapsa.o
	$(C) -c $(SOURCE_FOLDER)/Rules/FindValue.cpp -o $(OUTPUT_FOLDER)/FindValue.o
	$(C) -c $(SOURCE_FOLDER)/Rules/ArrOfKombinasi.cpp -o $(OUTPUT_FOLDER)/ArrOfKombinasi.o
	$(C) -c $(SOURCE_FOLDER)/utils/printColor.cpp -o $(OUTPUT_FOLDER)/printColor.o
	$(C) $(SOURCE_FOLDER)/main.cpp $(OUTPUT_FOLDER)/*.o -o $(OUTPUT_FOLDER)/main.exe
	@rm $(OUTPUT_FOLDER)/*.o

uff:
	g++ -o bin/main 	\
	src/main.cpp	\
	src/Card/*.cpp	\
	src/Exception/*.cpp	\
	src/GameManager/*.cpp	\
	src/Player/*.cpp	\
	src/Rules/*.cpp	\
	src/utils/*.cpp
	bin/main