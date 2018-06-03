OBJ =
CC = gcc
CFLAGS = -Wall -Werror

program: bin/main.o bin/game_opening.o bin/settings.o bin/menu.o
	$(CC) $(CFLAGS) bin/main.o bin/game_opening.o bin/settings.o bin/menu.o -o program

bin/main.o: src/main.c
	$(CC) -c -I include src/main.c -o bin/main.o

bin/game_opening.o: src/game_opening.c
	$(CC) -c -I include src/game_opening.c -o bin/game_opening.o 
	
bin/settings.o: src/settings.c
	$(CC) -c -I include src/settings.c -o bin/settings.o 

bin/menu.o: src/menu.c
	$(CC) -c -I include src/menu.c -o bin/menu.o 

bin:
	mkdir bin
	
clean:
	rm -rf bin
	
.PHONY: clean
