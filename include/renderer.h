#ifndef RENDERER_H
#define RENDERER_H

#include "model.h"

void renderer_init(void);
void renderer_clear(void);
void renderer_draw(const PlayerState *state);

#endif