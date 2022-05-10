#ifndef RENDER_H_
#define RENDER_H_

#include "../include/cards.h"
#include "../include/game.h"
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void render_init();
void render_destroy();
void render_hand(const Hand hand);
void render_usage();
void render_scores(const Hand player_hand, const Hand dealer_hand);
void render_outcome(const Hand player_hand, const Hand dealer_hand);

#endif // RENDER_H_
