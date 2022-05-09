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

/*
  research the difference in signature variations, i.e.,
  eval_hand(Hand *hand, uint8 position, uint8 score);
  also consider special exit in the case of BLACKJACK
*/
HandState eval_hand(Hand *hand, uint8_t pos) {
  bool has_ace = false;
  while (hand->cards[pos].is_dealt) {
    hand->score += rank_to_score(hand->cards[pos]);
    if (hand->cards[pos++].rank == ACE) has_ace = true;
  }
  if (has_ace && hand->score < 12) hand->score += 10;
  if (hand->score > 21) return BUSTED;
  return IN_ACTION;
}

HandState hit_hand(Hand *hand, Deck *deck) {
  uint8_t position = hand->num_cards; // mark location in hand where hit
  Card hit_card = deal_top_card(deck);
  append_to_hand(hand, hit_card);
  return eval_hand(hand, position);
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

Decision dealer_action(const Hand hand) {
  if (hand.score >= 17) return STAND;
  else return HIT;
}
