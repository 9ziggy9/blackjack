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
    printw("(%d, %d)\n", player_hand.score, player_hand.num_cards);
    switch((ch = getch())) {
      case 'q':
	quit = true;
	break;
      case 'h':
	hit_hand(&player_hand, &deck);
	/* if(hit_hand(&player_hand, &deck) == BUSTED) { */
	/*   goto clean_exit; */
	/* } */
	break;
      default:
	goto clean_exit;
    }

    render_hand(player_hand);
    render_hand(dealer_hand);
    refresh();
  }

clean_exit:
  render_destroy();
  printf("(%d,%d)\n", player_hand.score, player_hand.num_cards);
  return 0;
}
