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
      hand->num_cards++;
      break;
    }
    location++;
  }
}

Hand new_hand(Player player) {
  Hand hand;
  hand.score = 0;
  hand.num_cards = 0;
  hand.player = player;
  for (int i = 0; i < 12; i++) {
    hand.cards[i] = NULL_CARD;
  }
  return hand;
}

HandState eval_hand(Hand *hand) {
  uint8_t location = 0;
  uint8_t new_score = 0;
  bool has_ace = false;
  while (hand->cards[location].is_dealt) {
    new_score += rank_to_score(hand->cards[location]);
    if (hand->cards[location].rank == ACE) has_ace = true;
    location++;
  }
  if (has_ace && hand->score < 12) new_score += 10;
  hand->score = new_score;
  if (hand->score > 21) return BUSTED;
  return IN_ACTION;
}

HandState hit_hand(Hand *hand, Deck *deck) {
  Card hit_card = deal_top_card(deck);
  append_to_hand(hand, hit_card);
  return eval_hand(hand);
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
