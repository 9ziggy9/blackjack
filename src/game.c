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
  hand.score = 0;
  hand.player = player;
  for (int i = 0; i < 12; i++) {
    hand.cards[i] = NULL_CARD;
  }
  return hand;
}

HandState hit_hand(Hand *hand, Deck *deck) {
  // assertion to guard hit_hand() exposure for busted hands
  assert(hand->score < 22 && "\nHow did you get here? You busted.");

  int location = 0;

  Card hit_card = deal_top_card(deck);
  append_to_hand(hand, hit_card);

  // this return code will indicate to event loop that it needs
  // to move to endwin() stage via goto statement
  if (hand->score > 21) return BUSTED;

  hand->score += hit_card.rank;
  hand->num_cards++;

  return IN_ACTION;
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
