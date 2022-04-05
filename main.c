#include <stdio.h>

typedef struct {
  char suit;
  char rank;
} Card;

int main(void) {
  Card a_of_s = {.suit = 'S', .rank = 'a'};
  printf("Hello, world");
  return 0;
}
