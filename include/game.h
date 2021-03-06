#ifndef GAME_H_
#define GAME_H_
#include "./cards.h"
#include <assert.h>
#include <stdint.h>
#include <time.h>
#include <errno.h>

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

typedef enum {
  WIN,
  LOSS,
  PUSH
} Outcome;

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
void init_hands(Deck *deck, Hand *player_hand, Hand *dealer_hand);
int nanosleep(const struct timespec *__requested_time,
	      struct timespec *__remaining);
int msleep(long msec);

#endif //GAME_H_ 
