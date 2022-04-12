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

  // initialize curses system
  render_init();

  bool quit = false;
  while(!quit) {
    switch((ch = getch())) {
      case 'q':
	quit = true;
	break;
      case 'h':
	if(hit_hand(&player_hand, &deck) == BUSTED) {
	  printf("that is a bust\n");
	  printf("now you fucked up\n");
	  goto exit_now;
	}
	break;
      default:
	printf("you have fucked up now\n");
	goto exit_now;
    }

    render_hand(player_hand);
    render_hand(dealer_hand);
    refresh();
  }

exit_now:
  render_destroy();
  return 0;
}
