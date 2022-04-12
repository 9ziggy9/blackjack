#include "../include/game.h"

Card NULL_CARD = {NULL_CARD_R, NULL_CARD_S, false};

static Card deal_top_card(Deck *deck) {
  int location = 0;
  while (location < 52) {
    if (!deck->cards[location].is_dealt) {
      Card dealt_card = {
	deck->cards[location].rank,
	deck->cards[location].suit,
	true
      };
      deck->cards[location].is_dealt = true;
      return dealt_card;
    }
    location++;
  }
  return NULL_CARD;
}

static void append_to_hand(Hand *hand, Card card) {
  int location = 0;
  while (location < 12) {
    if (!hand->cards[location].is_dealt) {
      hand->cards[location] = card;
      break;
    }
    location++;
  }
}

Hand new_hand(Player player) {
  Hand hand;
  hand.num_cards = 0;
  hand.player = player;
  for (int i = 0; i < 12; i++) {
    hand.cards[i] = NULL_CARD;
  }
  return hand;
}

void hit_hand(Hand *hand, Deck *deck) {
  int location = 0;
  assert(hand->num_cards < 12);
  hand->num_cards++;
  Card hit_card = deal_top_card(deck);
  append_to_hand(hand, hit_card);
}

void print_hand(Hand hand) {
  int location = 0;
  printf("\n");
  while (location < 12) {
    printf("{%c, %c}\n", rank_to_symbol(hand.cards[location]),
	   suit_to_symbol(hand.cards[location]));
    location++;
  }
  printf("\n");
}
