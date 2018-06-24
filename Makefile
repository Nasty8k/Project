OBJ = build/main.o build/game_opening.o build/settings.o build/menu.o build/INFO.o build/ListPlayers.o
CC = gcc
CFLAGS = -Wall -Werror -std=c99

.PHONY: clean open

default: build bin bin/program

bin/program: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o bin/program

build/main.o: src/main.c
	$(CC) -c -I include src/main.c -o build/main.o

build/game_opening.o: src/game_opening.c
	$(CC) -c -I include src/game_opening.c -o build/game_opening.o 
	
build/settings.o: src/settings.c
	$(CC) -c -I include src/settings.c -o build/settings.o 

build/menu.o: src/menu.c
	$(CC) -c -I include src/menu.c -o build/menu.o

build/INFO.o: src/INFO.c
	$(CC) -c -I include src/INFO.c -o build/INFO.o 

build/ListPlayers.o: src/ListPlayers.c
	$(CC) -c -I include src/ListPlayers.c -o build/ListPlayers.o
		
clean:
	rm -rf bin build


build:
	mkdir build

bin:
	mkdir bin


open:
	./bin/program
