#include "../include/runtime.h"

RunTime quit() {
  printf("Goodbye!\n");
  return QUIT;
}

RunTime game(Deck *deck, Hand *player_hand, Hand *dealer_hand) {
  char ch;
  // runtime rendering, will update
  render_hand(*player_hand);
  render_hand(*dealer_hand);
  render_scores(*player_hand, *dealer_hand);
  // end runtime rendering
  switch((ch = getch())) {
    case 'q': return QUIT;
    case 'h':
      if (hit_hand(player_hand, deck) == BUSTED) return QUIT;
      return GAME;
    case 's':
      while (hit_hand(dealer_hand, deck) != BUSTED) {
	msleep(500);
	render_hand(*dealer_hand);
	refresh();
	if (dealer_action(*dealer_hand) == STAND) break;
      }
      msleep(500);
      return QUIT;
    default:
      return QUIT;
  }
}
