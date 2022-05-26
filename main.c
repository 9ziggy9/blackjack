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
  Hand player_hand = new_hand(PLAYER);
  Hand dealer_hand = new_hand(DEALER);
  hit_hand(&player_hand, &deck);
  hit_hand(&dealer_hand, &deck);

  // initialize curses system
  render_init();

  // initialization time rendering, will not update
  render_usage();

  RunTime runtime = GAME;
  while (runtime != QUIT) {
    if (runtime == GAME) runtime = game(&deck, &player_hand, &dealer_hand);
    if (runtime == GAMEOVER) runtime = game_over(&deck, &player_hand, &dealer_hand);
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
  return 0;
}
