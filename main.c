#include "./include/cards.h"
#include "./include/game.h"
#include "./include/render.h"
#include "./include/runtime.h"
#include <stdio.h>

int main(void) {
  // seed random number generator
  srand(time(NULL));

  Deck deck = assemble_deck();
  shuffle_deck(&deck);

  // initialize hands
  Hand player_hand;
  Hand dealer_hand;
  init_hands(&deck, &player_hand, &dealer_hand);

  // Number of deals between shuffles
  int GAME_COUNT = 0;

  // initialize curses system
  render_init();

  RunTime runtime = GAME;
  while (runtime != QUIT) {
    if (runtime == GAME) runtime = game(&deck, &player_hand, &dealer_hand);
    if (runtime == GAMEOVER) runtime = game_over(&deck, &player_hand,
						 &dealer_hand, &GAME_COUNT);
    refresh();
  }

  // runtime rendering, will update
  render_hand(player_hand);
  render_hand(dealer_hand);
  render_scores(player_hand, dealer_hand);
  refresh();

  /* bool outcome_menu = true; */
  /* while(outcome_menu) { */
  /*   render_outcome(player_hand, dealer_hand); */
  /*   switch((ch = getch())) { */
  /*     case 'q': */
  /* 	outcome_menu = false; */
  /* 	break; */
  /*     case 'p': */
  /* 	break; */
  /*   } */
  /*   refresh(); */
  /* } */

/* clean_exit: */
  render_destroy();
  printf("Thank you for playing!\n");
  print_deck(deck);
  return 0;
}
