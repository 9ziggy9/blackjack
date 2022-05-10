#include "./include/cards.h"
#include "./include/game.h"
#include "./include/render.h"
#include <stdio.h>
#include <time.h>
#include <errno.h>

int nanosleep(const struct timespec *__requested_time, struct timespec *__remaining);

int msleep(long msec) {
  struct timespec ts;
  int res;
  if (msec < 0) {
    errno = EINVAL;
    return -1;
  }
  ts.tv_sec = msec / 1000;
  ts.tv_nsec = (msec % 1000) * 1000000;
  do {
    res = nanosleep(&ts, &ts);
  } while (res && errno == EINTR);
  return res;
}

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

bool game_has_ended = false;
game_loop:
  while(!game_has_ended) {
    // runtime rendering, will update
    render_hand(player_hand);
    render_hand(dealer_hand);
    render_scores(player_hand, dealer_hand);
    // end runtime rendering
    switch((ch = getch())) {
      case 'q':
	goto clean_exit;
      case 'h':
	if (hit_hand(&player_hand, &deck) == BUSTED) game_has_ended = true;
	break;
      case 's':
	while (hit_hand(&dealer_hand, &deck) != BUSTED) {
	  msleep(500);
	  render_hand(dealer_hand);
	  refresh();
	  if (dealer_action(dealer_hand) == STAND) break;
	}
	msleep(500);
	game_has_ended = true;
	break;
      default:
	goto clean_exit;
    }
    refresh();
  }

  // runtime rendering, will update
  render_hand(player_hand);
  render_hand(dealer_hand);
  render_scores(player_hand, dealer_hand);
  refresh();

  bool outcome_menu = true;
  while(outcome_menu) {
    render_outcome(player_hand, dealer_hand);
    switch((ch = getch())) {
      case 'q':
	outcome_menu = false;
	break;
      case 'p':
	game_has_ended = false;
	goto game_loop;
    }
    refresh();
  }

clean_exit:
  render_destroy();
  printf("Thank you for playing!\n");
  return 0;
}
