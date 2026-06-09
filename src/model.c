#include "model.h"

void model_init(PlayerState *state) {
    state->x = 30;
    state->y = 15;
}

void model_update(PlayerState *state, InputCommand cmd) {
    if (cmd.move_up)    state->y--;
    if (cmd.move_down)  state->y++;
    if (cmd.move_left)  state->x--;
    if (cmd.move_right) state->x++;

    if (state->x < 0)            state->x = 0;
    if (state->y < 0)            state->y = 0;
    if (state->x > SCREEN_COLS - 1) state->x = SCREEN_COLS - 1;
    if (state->y > SCREEN_ROWS - 1) state->y = SCREEN_ROWS - 1;
}