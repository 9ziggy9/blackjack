#include "../include/cards.h"

char rank_to_symbol(Card card) {
  switch(card.rank) {
    case TWO: return '2';
    case THREE: return '3';
    case FOUR: return '4';
    case FIVE: return '5';
    case SIX: return '6';
    case SEVEN: return '7';
    case EIGHT: return '8';
    case NINE: return '9';
    case TEN: return 'T';
    case JACK: return 'J';
    case QUEEN: return 'Q';
    case KING: return 'K';
    case ACE: return 'A';
    default: return 'X';
  }
}

char suit_to_symbol(Card card) {
  switch(card.suit) {
  case HEARTS: return 'H';
  case CLUBS: return 'C';
  case DIAMONDS: return 'D';
  case SPADES: return 'S';
  default: return 'X';
  }
}

Deck assemble_deck() {
  Deck deck;
  int place = 0;
  for (Suit suit = HEARTS; suit <= SPADES; suit++) {
    for (Rank rank = TWO; rank <= ACE; rank++) {
      Card new_card = {rank, suit, false};
      deck.cards[place++] = new_card;
    }
  }
  return deck;
}

void swap(Card *a, Card *b) {
  Card tmp = *a;
  *a = *b;
  *b = tmp;
}

void shuffle_deck(Deck *deck) {
  for (int i = 51; i > 0; i--) {
    int j = rand() % (i+1);
    swap(&deck->cards[i], &deck->cards[j]);
  }
}

void print_deck(Deck deck) {
  for (int i = 0; i < 52; i++) {
    printf("{ ");
    printf("%c, %c, %s", rank_to_symbol(deck.cards[i]),
	                 suit_to_symbol(deck.cards[i]),
	                 deck.cards[i].is_dealt ? "true" : "false");
    printf(" }");
  }
  printf("\n");
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
