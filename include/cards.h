#ifndef CARDS_H_
#define CARDS_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
  TWO = 2,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING,
  ACE,
  NULL_CARD_R
} Rank;

typedef enum { HEARTS, CLUBS, DIAMONDS, SPADES, NULL_CARD_S } Suit;

typedef struct {
  Rank rank;
  Suit suit;
  bool is_dealt;
} Card;

typedef struct {
  Card cards[52];
} Deck;

extern Card NULL_CARD;

char rank_to_symbol(Card card);
char suit_to_symbol(Card card);
Deck assemble_deck();
void swap(Card *a, Card *b);
void shuffle_deck(Deck *deck);
void print_deck(Deck deck);
void print_card(Card card);
uint8_t rank_to_score(Card card);

#endif // CARDS_H_
