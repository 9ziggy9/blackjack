#include "./include/cards.h"
#include "./include/game.h"
#include "./include/render.h"
#include <stdio.h>
#include <time.h>

int main(void) {
  // seed random number generator
  srand(time(NULL));
  char ch;

  Deck deck = assemble_deck();
  shuffle_deck(&deck);
  print_deck(deck);

  Hand player_hand = new_hand();
  Hand dealer_hand = new_hand();
  print_hand(player_hand);
  print_hand(dealer_hand);

  hit_hand(&player_hand, &deck);
  hit_hand(&dealer_hand, &deck);

  print_deck(deck);

  printf("PLAYER HAND: ");
  print_hand(player_hand);
  printf("DEALER HAND: ");
  print_hand(dealer_hand);

  hit_hand(&player_hand, &deck);
  hit_hand(&dealer_hand, &deck);

  print_deck(deck);

  printf("PLAYER HAND: ");
  print_hand(player_hand);
  printf("DEALER HAND: ");
  print_hand(dealer_hand);

  Card card = {ACE, SPADES};

  // initialize curses system
  render_init();

  while((ch = getch() != 'q')) {
    render_phand1(card);
    refresh();
  }

  render_destroy();
  return 0;
}
