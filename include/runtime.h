#ifndef RUNTIME_H_
#define RUNTIME_H_

#include <stdio.h>
#include "../include/render.h"
#include "../include/game.h"

typedef enum {
  START,
  GAME,
  GAMEOVER,
  MENU,
  QUIT
} RunTime;

RunTime quit();
RunTime game(Deck *deck, Hand *player_hand, Hand *dealer_hand);
RunTime game_over(Deck *deck, Hand *player_hand, Hand *dealer_hand);

#endif
