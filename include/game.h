#ifndef GAME_H_
#define GAME_H_
#include "./cards.h"

typedef enum {
  PLAYER,
  DEALER
} Player;

typedef struct {
  int num_cards;
  Card cards[12];
  Player player;
} Hand;

Card deal_top_card(Deck *deck);
Hand new_hand();
void append_to_hand(Hand *hand, Card card);
void hit_hand(Hand *hand, Deck *deck);
void print_hand(Hand hand);

#endif //GAME_H_ 
