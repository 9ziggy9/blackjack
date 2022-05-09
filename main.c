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

  // initialize hands
  Hand player_hand = new_hand(PLAYER);
  Hand dealer_hand = new_hand(DEALER);
  hit_hand(&player_hand, &deck);
  hit_hand(&dealer_hand, &deck);

  // initialize curses system
  render_init();

  // initialization time rendering, will not update
  render_usage();

  bool quit = false;
  while(!quit) {
    // runtime rendering, will update
    render_hand(player_hand);
    render_hand(dealer_hand);
    // end runtime rendering
    switch((ch = getch())) {
      case 'q':
	quit = true;
	break;
      case 'h':
	if (hit_hand(&player_hand, &deck) == BUSTED) {
	  goto clean_exit;
	}
	break;
      case 's':
	while (hit_hand(&dealer_hand, &deck) != BUSTED) {
	  render_hand(dealer_hand);
	}
	break;
      default:
	goto clean_exit;
    }
    refresh();
  }

clean_exit:
  render_destroy();
  printf("(%d,%d)\n", player_hand.score, player_hand.num_cards);
  print_hand(player_hand);
  return 0;
}
