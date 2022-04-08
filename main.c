#include <stdio.h>
#include "./include/cards.h"
#include "./include/game.h"

int main(void) {
  // seed random number generator
  srand(time(NULL));

  Deck deck = assemble_deck();
  print_deck(deck);

  return 0;
}
