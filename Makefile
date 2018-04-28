OBJ =
CC = gcc
CFLAGS = -Wall -Werror

program: bin/main.o bin/game_opening.o
	$(CC) $(CFLAGS) bin/main.o bin/game_opening.o -o program

bin/main.o: src/main.c
	$(CC) -c -I include src/main.c -o bin/main.o

bin/game_opening.o: src/game_opening.c
	$(CC) -c -I include src/game_opening.c -o bin/game_opening.o 

bin:
	mkdir bin
	
clean:
	rm -rf bin
	
.PHONY: clean

