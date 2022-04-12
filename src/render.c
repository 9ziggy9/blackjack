#include "../include/render.h"

static int PHAND1_X = 5;
static int PHAND1_Y = 20;
static int DHAND_X = 5;
static int DHAND_Y = 5;

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
  render_top_card(hand.cards[0], PHAND1_X, PHAND1_Y);
}
