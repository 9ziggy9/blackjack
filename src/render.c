#include "../include/render.h"
#include <curses.h>

static const int PHAND1_X = 5;
static const int PHAND1_Y = 20;
static const int DHAND_X = 5;
static const int DHAND_Y = 5;
static int ROW, COL;
const static int CARD_SIZE = 7;

static int x_center(int length) { return (COL - length) / 2; }
static int y_center(int length) { return (ROW - length) / 2; }

void render_init() {
  initscr();
  cbreak();
  noecho(); // silence keyboard input echoing
  getmaxyx(stdscr, ROW, COL); // window dims
  keypad(stdscr, TRUE);
  curs_set(0);
  refresh();
}

void render_destroy() {
  endwin();
}

static void render_top_card(const Card card, int x, int y) {
  mvprintw(y,     x_center(CARD_SIZE) + x - 8,  "_______");
  mvprintw(y + 1, x_center(CARD_SIZE) + x - 9, "|%c      |", rank_to_symbol(card));
  mvprintw(y + 2, x_center(CARD_SIZE) + x - 9, "|       |");
  mvprintw(y + 3, x_center(CARD_SIZE) + x - 9, "|   %c   |", suit_to_symbol(card));
  mvprintw(y + 4, x_center(CARD_SIZE) + x - 9, "|       |");
  mvprintw(y + 5, x_center(CARD_SIZE) + x - 9, "|______%c|", rank_to_symbol(card));
}

static void render_bottom_card(const Card card, int x, int y) {
  mvprintw(y,     x_center(CARD_SIZE) + x - 8,  "__");
  mvprintw(y + 1, x_center(CARD_SIZE) + x - 9, "|%c", rank_to_symbol(card));
  mvprintw(y + 2, x_center(CARD_SIZE) + x - 9, "|  ");
  mvprintw(y + 3, x_center(CARD_SIZE) + x - 9, "|  ");
  mvprintw(y + 4, x_center(CARD_SIZE) + x - 9, "|  ");
  mvprintw(y + 5, x_center(CARD_SIZE) + x - 9, "|______%c|", rank_to_symbol(card));
}

static Outcome game_outcome(const Hand player_hand, const Hand dealer_hand) {
  if (player_hand.score > 21) return LOSS;
  if (dealer_hand.score > 21) return WIN;
  if (player_hand.score == dealer_hand.score) return PUSH;
  if (dealer_hand.score > player_hand.score) return LOSS;
  else return WIN;
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

void render_usage() {
  mvprintw(0, 0, "h to hit");
  mvprintw(1, 0, "s to stand");
  mvprintw(2, 0, "q to quit");
}

void render_scores(const Hand player_hand, const Hand dealer_hand) {
  mvprintw(ROW - 2, 0, "dealer: %d", dealer_hand.score);
  mvprintw(ROW - 1, 0, "player: %d", player_hand.score);
}

void render_outcome(const Hand player_hand, const Hand dealer_hand) {
  move(ROW/2,0); // target line
  clrtoeol(); // clear line
  switch (game_outcome(player_hand, dealer_hand)) {
    case LOSS:
      mvprintw(ROW/2, COL/2 - 8, "YOU LOSE!");
      break;
    case WIN:
      mvprintw(ROW/2, COL/2 - 8, "YOU WIN!");
      break;
    case PUSH:
      mvprintw(ROW/2, COL/2 - 8, "YOU PUSH!");
      break;
  };
}
