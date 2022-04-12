#ifndef RENDER_H_
#define RENDER_H_

#include "../include/cards.h"
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void render_top_card(Card card, int x, int y);
void render_init();
void render_destroy();

#endif // RENDER_H_
