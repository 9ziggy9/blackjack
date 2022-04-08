#include "./include/cards.h"
#include "./include/game.h"

int main(void) {
  // seed random number generator
  srand(time(NULL));

  // create dealer/player hands
  Hand player_hand = new_hand();
  Hand dealer_hand = new_hand();
  print_hand(player_hand);
  print_hand(dealer_hand);

  // Shuffle, shuffle
  Deck deck = assemble_deck();
  shuffle_deck(&deck);

  // Playing game
  hit_hand(&player_hand, &deck);
  return 0;
}
