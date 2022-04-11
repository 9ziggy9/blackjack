#include "../include/render.h"

/* void render_card(Card card, int height, int width, */
/* 		 int origin_y, int origin_x) */
/* { */
/*   mvprintw(origin_y + 1, origin_x - width + 2, "%c    ", 'h'); */
/*   mvprintw(origin_y + 2, origin_x - width + 2, "  %c  ", 'l'); */
/*   mvprintw(origin_y + 3, origin_x - width + 2, "     %c", 'o'); */
/* } */

void render_card() {
  mvprintw(30, 30, "%c", 'h');
  mvprintw(35, 35, "%c", 'l');
  mvprintw(40, 40, "%c", 'k');
}
