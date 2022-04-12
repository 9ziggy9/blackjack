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

  Hand player_hand = new_hand(PLAYER);
  Hand dealer_hand = new_hand(DEALER);

  /* hit_hand(&player_hand, &deck); */
  /* hit_hand(&dealer_hand, &deck); */

  /* hit_hand(&player_hand, &deck); */
  /* hit_hand(&dealer_hand, &deck); */

  // initialize curses system
  render_init();

  bool quit = false;
  while(!quit) {
    switch((ch = getch())) {
      case 'q':
	quit = true;
	break;
      case 'h':
	hit_hand(&player_hand, &deck);
	break;
      default:
	assert(0 && "you haven't implemented other keys");
    }

    render_hand(player_hand);
    render_hand(dealer_hand);
    refresh();
  }

  render_destroy();
  return 0;
}
