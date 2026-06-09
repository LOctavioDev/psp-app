#ifndef MODEL_H
#define MODEL_H

#include "input.h"

#define SCREEN_COLS 68
#define SCREEN_ROWS 34

typedef struct {
    int x;
    int y;
} PlayerState;

void model_init(PlayerState *state);
void model_update(PlayerState *state, InputCommand cmd);

#endif