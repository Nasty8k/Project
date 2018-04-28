OBJ =
CC = gcc
CFLAGS = -Wall -Werror

program: bin/main.o bin/settings.o
	$(CC) $(CFLAGS) bin/main.o bin/settings.o -o program

bin/main.o: src/main.c
	$(CC) -c -I include src/main.c -o bin/main.o

bin/settings.o: src/settings.c
	$(CC) -c -I include src/settings.c -o bin/settings.o 

bin:
	mkdir bin
	
clean:
	rm -rf bin
	
.PHONY: clean
