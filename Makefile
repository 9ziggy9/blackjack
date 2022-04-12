INCLUDES=-I ./include
CFLAGS=-Wall -std=c11 -pedantic
DFLAGS=-ggdb
OFLAGS=-O3
OBJECTS=./build/game.o ./build/cards.o ./build/render.o
LIBS=-lncurses
BIN_DIR=$(HOME)/bin

all: game card render blackjack

blackjack: main.c $(OBJECTS)
	$(CC) $(INCLUDES) $(CFLAGS) main.c $(OBJECTS) $(LIBS) -o blackjack

card: src/cards.c
	$(CC) $(INCLUDES) -g ./src/cards.c -c -o ./build/cards.o

game: src/game.c
	$(CC) $(INCLUDES) -g ./src/game.c -c -o ./build/game.o

render: src/render.c
	$(CC) $(INCLUDES) -g ./src/render.c -c -o ./build/render.o

debug: game card render main.c $(OBJECTS)
	$(CC) $(INCLUDES) $(CFLAGS) $(DFLAGS) main.c $(OBJECTS) $(LIBS) -o blackjack

opt: game card render main.c $(OBJECTS)
	$(CC) $(INCLUDES) $(CFLAGS) $(OFLAGS) main.c $(OBJECTS) $(LIBS) -o blackjack

install: game card render main.c $(OBJECTS)
	$(info Installing to home bin directory ---> $(BIN_DIR))
	$(CC) $(INCLUDES) $(CFLAGS) main.c $(OBJECTS) $(LIBS) -o $(BIN_DIR)/blackjack

uninstall: clean
	rm -rf $(BIN_DIR)/blackjack

clean:
	rm -rf ./blackjack ./build/*
