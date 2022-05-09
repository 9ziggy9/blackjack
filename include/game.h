#ifndef GAME_H_
#define GAME_H_
#include "./cards.h"
#include <assert.h>
#include <stdint.h>

typedef enum {
  PLAYER,
  DEALER
} Player;

typedef enum {
  IN_ACTION,
  BUSTED,
  BLACKJACK
} HandState;

typedef enum {
  HIT,
  STAND
} Decision;

typedef struct {
  uint8_t score;
  uint8_t num_cards;
  Card cards[12];
  Player player;
} Hand;

Hand new_hand(Player player);
HandState hit_hand(Hand *hand, Deck *deck);
void print_hand(Hand hand);
HandState eval_hand(Hand *hand, uint8_t pos);
Decision dealer_action(const Hand hand);

#endif //GAME_H_ 
