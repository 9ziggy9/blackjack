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

typedef struct {
  Card cards[52];
} Deck;

Deck assemble_deck() {
  Deck deck;
  int place = 0;
  for (Suit suit = HEARTS; suit <= SPADES; suit++) {
    for (Rank rank = TWO; rank <= ACE; rank++) {
      Card new_card = {rank, suit};
      deck.cards[place++] = new_card;
    }
  }
  return deck;
}

char rank_to_symbol(Card card) {
  switch(card.rank) {
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
    case 10: return 'T';
    case 11: return 'J';
    case 12: return 'Q';
    case 13: return 'K';
    case 14: return 'A';
    default: return 'X';
  }
}

char suit_to_symbol(Card card) {
  switch(card.suit) {
  case 0: return 'H';
  case 1: return 'C';
  case 2: return 'D';
  case 3: return 'S';
  default: return 'X';
  }
}

void print_deck(Deck deck) {
  for (int i = 0; i < 52; i++) {
    printf("{ ");
    printf("%c, %c", rank_to_symbol(deck.cards[i]),
	             suit_to_symbol(deck.cards[i]));
    printf(" }");
  }
}

void render_card(Card card) {
  printf(" _______\n");
  printf("|%c      |\n", rank_to_symbol(card));
  printf("|       |\n");
  printf("|       |\n");
  printf("|   %c   |\n", suit_to_symbol(card));
  printf("|       |\n");
  printf("|       |\n");
  printf("|______%c|\n", rank_to_symbol(card));
}

int main(void) {
  Card a_of_s = {ACE, SPADES};
  Card seven_of_c = {SEVEN, CLUBS};
  render_card(a_of_s);
  render_card(seven_of_c);
  Deck deck = assemble_deck();
  print_deck(deck);
  return 0;
}
