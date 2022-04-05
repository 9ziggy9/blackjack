#include <stdio.h>

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
} Card;

void print_card(Card card) {
  /* _______ */
  /*|A      |*/
  /*|       |*/
  /*|       |*/
  /*|   ♠   |*/
  /*|       |*/
  /*|       |*/
  /*|______A|*/
  printf("%d, ", card.rank);
  printf("%d\n", card.suit);
}

int main(void) {
  Card a_of_s = {ACE, SPADES};
  print_card(a_of_s);
  printf("Hello, world");
  return 0;
}
