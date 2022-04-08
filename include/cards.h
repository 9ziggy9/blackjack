#ifndef CARDS_H_
#define CARDS_H_

typedef enum {
  TWO = 2,
  THREE, FOUR, FIVE, SIX,
  SEVEN, EIGHT, NINE, TEN,
  JACK, QUEEN, KING, ACE,
  NULL_CARD_R
} Rank;

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

char rank_to_symbol(Card card);
char suit_to_symbol(Card card);
Deck assemble_deck();
void swap(Card *a, Card *b);
void shuffle_deck(Deck *deck);
void print_deck(Deck deck);
void render_card(Card card);

#endif // CARDS_H_
