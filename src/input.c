#include <pspctrl.h>
#include "input.h"

void input_init(void) {
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_DIGITAL);
}

InputCommand input_read(void) {
    SceCtrlData pad;
    InputCommand cmd = {0, 0, 0, 0};

    sceCtrlReadBufferPositive(&pad, 1);

    cmd.move_up    = (pad.Buttons & PSP_CTRL_UP)    ? 1 : 0;
    cmd.move_down  = (pad.Buttons & PSP_CTRL_DOWN)  ? 1 : 0;
    cmd.move_left  = (pad.Buttons & PSP_CTRL_LEFT)  ? 1 : 0;
    cmd.move_right = (pad.Buttons & PSP_CTRL_RIGHT) ? 1 : 0;

    return cmd;
}