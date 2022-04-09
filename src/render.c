#include "../include/render.h"

void render_card(Card card, int height, int width, int origin_y, int origin_x) {
  mvprintw(origin_y + 1, origin_x - width + 2, "%c    ");
  mvprintw(origin_y + 2, origin_x - width + 2, "  %c  ");    
  mvprintw(origin_y + 3, origin_x - width + 2, "     %c");
}
