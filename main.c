#include <stdio.h>
#include <stdbool.h>

typedef enum {
  TWO = 2,
  THREE, FOUR, FIVE, SIX,
  SEVEN, EIGHT, NINE, TEN,
  JACK, QUEEN, KING, ACE
} Rank;

typedef enum {
  HEARTS, CLUBS, DIAMONDS, SPADES
} Suit;

typedef struct {
  Rank rank;
  Suit suit;
  bool is_dealt;
} Card;

void render_card(Card card) {

  /* _______ 
    |A      |
    |       |
    |       |
    |   S   |
    |       |
    |       |
    |______A| */

  printf(" _______\n");
  printf("|A      |\n");
  printf("|       |\n");
  printf("|       |\n");
  printf("|   S   |\n");
  printf("|       |\n");
  printf("|       |\n");
  printf("|______A|\n");
}

int main(void) {
  Card a_of_s = {ACE, SPADES};
  render_card(a_of_s);
  return 0;
}
