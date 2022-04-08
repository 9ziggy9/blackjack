INCLUDES=-I ./include
CFLAGS=-Wall -ggdb -std=c11 -pedantic
OBJECTS=./build/game.o ./build/cards.o

all: card game blackjack

blackjack: main.c $(OBJECTS)
	$(CC) $(INCLUDES) $(CFLAGS) main.c $(OBJECTS) $(LIBS) -o blackjack

card: src/cards.c
	$(CC) $(INCLUDES) -g ./src/cards.c -c -o ./build/cards.o

game: src/game.c
	$(CC) $(INCLUDES) -g ./src/game.c -c -o ./build/game.o

clean:
	rm -rf ./blackjack ./build/*
