#include <pspkernel.h>
#include <pspdisplay.h>

#include "sys_utils.h"
#include "input.h"
#include "model.h"
#include "renderer.h"

PSP_MODULE_INFO("ControlCruceta", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

int main(void) {
    renderer_init();
    SetupCallbacks();
    input_init();

    PlayerState player;
    model_init(&player);

    while (1) {
        renderer_clear();

        InputCommand cmd = input_read();
        model_update(&player, cmd);
        renderer_draw(&player);

        sceDisplayWaitVblankStart();
    }

    return 0;
}