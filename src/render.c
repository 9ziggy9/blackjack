#include "../include/render.h"

static const int PHAND1_X = 5;
static const int PHAND1_Y = 20;
static const int DHAND_X = 5;
static const int DHAND_Y = 5;
static int ROW, COL;
const static int CARD_SIZE = 7;

static int calc_center(int length) {
  return (COL - length) / 2;
}

void render_init() {
  initscr();
  cbreak();
  getmaxyx(stdscr, ROW, COL);
  keypad(stdscr, TRUE);
  curs_set(0);
  refresh();
}

void render_destroy() {
  endwin();
}

static void render_top_card(const Card card, int x, int y) {
  mvprintw(y,     calc_center(CARD_SIZE) + x - 7,  "_______");
  mvprintw(y + 1, calc_center(CARD_SIZE) + x - 8, "|%c      |", rank_to_symbol(card));
  mvprintw(y + 2, calc_center(CARD_SIZE) + x - 8, "|       |");
  mvprintw(y + 3, calc_center(CARD_SIZE) + x - 8, "|   %c   |", suit_to_symbol(card));
  mvprintw(y + 4, calc_center(CARD_SIZE) + x - 8, "|       |");
  mvprintw(y + 5, calc_center(CARD_SIZE) + x - 8, "|______%c|", rank_to_symbol(card));
}

static void render_bottom_card(const Card card, int x, int y) {
  mvprintw(y,     calc_center(CARD_SIZE) + x - 7,  "__");
  mvprintw(y + 1, calc_center(CARD_SIZE) + x - 8, "|%c", rank_to_symbol(card));
  mvprintw(y + 2, calc_center(CARD_SIZE) + x - 8, "|  ");
  mvprintw(y + 3, calc_center(CARD_SIZE) + x - 8, "|  ");
  mvprintw(y + 4, calc_center(CARD_SIZE) + x - 8, "|  ");
  mvprintw(y + 5, calc_center(CARD_SIZE) + x - 8, "|______%c|", rank_to_symbol(card));
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

void render_player_score(const Hand hand) {
  assert(0 && "not yet implemented!\n");
}

void render_usage() {
  mvprintw(0, 0, "h to hit");
  mvprintw(1, 0, "s to stand");
  mvprintw(2, 0, "q to quit");
}
