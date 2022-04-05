#include <stdio.h>

typedef struct {
  char suit;
  char rank;
} Card;

typedef enum {
  TWO = 2,
  THREE, FOUR, FIVE, SIX,
  SEVEN, EIGHT, NINE, TEN,
  JACK, QUEEN, KING, ACE
};

void print_card(Card card) {
  /* _______ */
  /*|A      |*/
  /*|       |*/
  /*|       |*/
  /*|   ♠   |*/
  /*|       |*/
  /*|       |*/
  /*|______A|*/
}

int main(void) {
  Card a_of_s = {.suit = 'S', .rank = 'a'};
  printf("Hello, world");
  return 0;
}
