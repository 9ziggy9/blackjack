INCLUDES=-I ./include
CFLAGS=-Wall -std=c11 -pedantic
DFLAGS=-ggdb
OFLAGS=-O3
OBJECTS=./build/game.o ./build/cards.o ./build/render.o ./build/runtime.o
LIBS=-lncurses
BIN_DIR=$(HOME)/bin

all: game card render runtime blackjack

.ONESHELL:
install: game card render main.c $(OBJECTS)
	@echo
	echo "--- Building blackjack in $(BIN_DIR) ---"
	echo -e '\033[0;37m' #dark gray
	read -p "Proceed with install (y/N)? " choice; \
	if [[ $$choice != "y" ]]; then echo "INSTALL ABORTED"; \
	exit; fi
ifneq ("$(wildcard $(BIN_DIR))", "")
	echo -e '\033[0;32m' #green
	echo "Compiling ---> $(BIN_DIR)/blackjack"
	echo -e '\033[0;37m' #dark gray
	echo "$(CC) $(INCLUDES) $(CFLAGS) main.c $(OBJECTS) $(LIBS) -o $(BIN_DIR)/blackjack"
	echo -e '\033[0;37m' #bright white
	$(CC) $(INCLUDES) $(CFLAGS) main.c $(OBJECTS) $(LIBS) -o $(BIN_DIR)/blackjack
	echo -e "\033[1;32m --- Installation Successful ---"
else
	echo 
	echo -e "\033[0;31mWARNING\033[0m: $(BIN_DIR) does not exist."
	echo -e "\033[0;32mCreating $(BIN_DIR) now.\033[0;37m"
	echo "mkdir -p $(BIN_DIR)"
	mkdir -p $(BIN_DIR)
	echo
	echo -e "\033[0mCompiling ---> $(BIN_DIR)/blackjack\033[0;37m"
	echo "$(CC) $(INCLUDES) $(CFLAGS) main.c $(OBJECTS) $(LIBS) -o $(BIN_DIR)/blackjack"
	$(CC) $(INCLUDES) $(CFLAGS) main.c $(OBJECTS) $(LIBS) -o $(BIN_DIR)/blackjack
	echo 
	echo -e "\033[1;32m --- Installation Successful ---"
endif

blackjack: main.c $(OBJECTS)
	$(CC) $(INCLUDES) $(CFLAGS) main.c $(OBJECTS) $(LIBS) -o blackjack

card: src/cards.c
	$(CC) $(INCLUDES) -g ./src/cards.c -c -o ./build/cards.o

game: src/game.c
	$(CC) $(INCLUDES) -g ./src/game.c -c -o ./build/game.o

runtime: src/runtime.c
	$(CC) $(INCLUDES) -g ./src/runtime.c -c -o ./build/runtime.o

render: src/render.c
	$(CC) $(INCLUDES) -g ./src/render.c -c -o ./build/render.o

debug: game card render main.c $(OBJECTS)
	$(CC) $(INCLUDES) $(CFLAGS) $(DFLAGS) main.c $(OBJECTS) $(LIBS) -o blackjack

opt: game card render main.c $(OBJECTS)
	$(CC) $(INCLUDES) $(CFLAGS) $(OFLAGS) main.c $(OBJECTS) $(LIBS) -o blackjack

uninstall: clean
	rm -rf $(BIN_DIR)/blackjack

clean:
	rm -rf ./blackjack ./build/*
