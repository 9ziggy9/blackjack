#include "../include/render.h"

static int PHAND1_X = 5;
static int PHAND1_Y = 5;

void render_phand1(Card card) {
  mvprintw(PHAND1_Y, PHAND1_X,          "_______");
  mvprintw(PHAND1_Y + 1, PHAND1_X - 1, "|%c      |",
	   rank_to_symbol(card));
  mvprintw(PHAND1_Y + 2, PHAND1_X - 1, "|       |");
  mvprintw(PHAND1_Y + 3, PHAND1_X - 1, "|   %c   |",
	   suit_to_symbol(card));
  mvprintw(PHAND1_Y + 4, PHAND1_X - 1, "|       |");
  mvprintw(PHAND1_Y + 5, PHAND1_X - 1, "|______%c|",
	   rank_to_symbol(card));
}

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
