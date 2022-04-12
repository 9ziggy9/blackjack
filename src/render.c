#include "../include/render.h"

static const int PHAND1_X = 5;
static const int PHAND1_Y = 20;
static const int DHAND_X = 5;
static const int DHAND_Y = 5;

void render_init() {
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);
  printw("Hello, world");
  refresh();
}

void render_destroy() {
  endwin();
}

static void render_top_card(const Card card, int x, int y) {
  mvprintw(y, x,          "_______");
  mvprintw(y + 1, x - 1, "|%c      |", rank_to_symbol(card));
  mvprintw(y + 2, x - 1, "|       |");
  mvprintw(y + 3, x - 1, "|   %c   |", suit_to_symbol(card));
  mvprintw(y + 4, x - 1, "|       |");
  mvprintw(y + 5, x - 1, "|______%c|", rank_to_symbol(card));
}

static void render_bottom_card(const Card card, int x, int y) {
  mvprintw(y, x,          "__");
  mvprintw(y + 1, x - 1, "|%c", rank_to_symbol(card));
  mvprintw(y + 2, x - 1, "|  ");
  mvprintw(y + 3, x - 1, "|  ");
  mvprintw(y + 4, x - 1, "|  ");
  mvprintw(y + 5, x - 1, "|______%c|", rank_to_symbol(card));
}

void render_hand(const Hand hand) {
  int hand_origin_x;
  int hand_origin_y;

  switch(hand.player) {
    case PLAYER:
      hand_origin_x = PHAND1_X;
      hand_origin_y = PHAND1_Y;
      break;
    case DEALER:
      hand_origin_x = DHAND_X;
      hand_origin_y = DHAND_Y;
      break;
    default:
      assert(0 && "what the fuck happened?\n");
  }

  int location = 0;
  while(location < hand.num_cards - 1) {
    render_bottom_card(hand.cards[location], hand_origin_x + 2 * location,
					     hand_origin_y - location);
    location++;
  }
  render_top_card(hand.cards[location], hand_origin_x + 2 * location,
					hand_origin_y - location);
}
