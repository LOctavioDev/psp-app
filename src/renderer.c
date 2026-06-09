#include <pspdebug.h>
#include "renderer.h"

void renderer_init(void) {
    pspDebugScreenInit();
}

void renderer_clear(void) {
    pspDebugScreenClear();
}

void renderer_draw(const PlayerState *state) {
    pspDebugScreenSetXY(0, 0);
    pspDebugScreenPrintf("X: %d | Y: %d (Usa las flechas D-Pad)", state->x, state->y);

    pspDebugScreenSetXY(state->x, state->y);
    pspDebugScreenPrintf("[O]");
}