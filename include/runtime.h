#ifndef RUNTIME_H_
#define RUNTIME_H_

#include <stdio.h>
#include "../include/render.h"

typedef enum {
  START,
  GAME,
  GAMEOVER,
  MENU,
  QUIT
} RunTime;

void hello_runtime();
RunTime game(Deck *deck, Hand *player_hand, Hand *dealer_hand);

#endif
