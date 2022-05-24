#ifndef RUNTIME_H_
#define RUNTIME_H_

#include <stdio.h>

typedef enum {
  START,
  GAME,
  GAMEOVER,
  MENU,
  QUIT
} RunTime;

void hello_runtime();

#endif
