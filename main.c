#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
  TWO = 2,
  THREE, FOUR, FIVE, SIX,
  SEVEN, EIGHT, NINE, TEN,
  JACK, QUEEN, KING, ACE,
  NULL_CARD_R
} Rank;

typedef enum {
  PLAYER,
  DEALER
} Player;

typedef enum {
  HEARTS, CLUBS, DIAMONDS, SPADES,
  NULL_CARD_S
} Suit;

typedef struct {
  Rank rank;
  Suit suit;
  bool is_dealt;
} Card;

typedef struct {
  Card cards[52];
} Deck;

typedef struct {
  int num_cards;
  Card cards[12];
  Player player;
} Hand;

// GLOBAL VARS
Card NULL_CARD = {NULL_CARD_R, NULL_CARD_S, false};

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

Card deal_top_card(Deck *deck) {
  int location = 0;
  while (location < 52) {
    if (!deck->cards[location].is_dealt) {
      Card dealt_card = {
	deck->cards[location].rank,
	deck->cards[location].suit
      };
      deck->cards[location].is_dealt = true;
      return dealt_card;
    }
    location++;
  }
  return NULL_CARD;
}

Hand new_hand() {
  Hand hand;
  int location = 0;
  while (location++ < 12) {
    hand.cards[location] = NULL_CARD;
  }
  return hand;
}

void append_to_hand(Hand *hand, Card card) {
  int location = 0;
  while (location++ < 12) {
    if (!hand->cards[location].is_dealt) {
      hand->cards[location] = card;
    }
  }
}

void hit_hand(Hand *hand, Deck *deck) {
  int location = 0;
  Card hit_card = deal_top_card(deck);
  append_to_hand(hand, hit_card);
}

void print_hand(Hand hand) {
  int location = 0;
  printf("\n");
  while (location++ < 12) {
    printf("{%c, %c}\n", rank_to_symbol(hand.cards[location]),
	   suit_to_symbol(hand.cards[location]));
  }
  printf("\n");
}

int main(void) {
  // seed random number generator
  srand(time(NULL));

  // create dealer/player hands
  Hand player_hand = new_hand();
  Hand dealer_hand = new_hand();
  print_hand(player_hand);

  // Shuffle, shuffle
  Deck deck = assemble_deck();
  shuffle_deck(&deck);

  // Playing game
  hit_hand(&player_hand, &deck);
  return 0;
}
