#include <stdio.h>

typedef struct {
  char suit;
  char rank;
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

}

int main(void) {
  Card a_of_s = {.suit = 'S', .rank = 'a'};
  printf("Hello, world");
  return 0;
}
