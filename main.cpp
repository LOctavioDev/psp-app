#include <pspkernel.h>
#include <pspdebug.h>

PSP_MODULE_INFO("FocoAnimado", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

#define COLOR_AMARILLO 0xFF00FFFF
#define COLOR_GRIS     0xFF555555
#define COLOR_BLANCO   0xFFFFFFFF

int exit_callback(int arg1, int arg2, void *common) {
    sceKernelExitGame();
    return 0;
}
int CallbackThread(SceSize args, void *argp) {
    int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    sceKernelRegisterExitCallback(cbid);
    sceKernelSleepThreadCB();
    return 0;
}
void SetupCallbacks(void) {
    int thid = sceKernelCreateThread("update_thread", CallbackThread, 0x11, 0xFA0, 0, 0);
    if(thid >= 0) sceKernelStartThread(thid, 0, 0);
}

void dibujar_foco(int encendido) {
    pspDebugScreenClear();
    
    pspDebugScreenPrintf("\n\n\n\n\n");

    if (encendido) {
        pspDebugScreenSetTextColor(COLOR_AMARILLO);
        pspDebugScreenPrintf("           .---.        \n");
        pspDebugScreenPrintf("          /     \\       \n");
        pspDebugScreenPrintf("         |       |      \n");
        pspDebugScreenPrintf("          \\     /       \n");
        pspDebugScreenPrintf("           |===|        \n");
        pspDebugScreenPrintf("           '---'        \n");
        pspDebugScreenSetTextColor(COLOR_BLANCO);
        pspDebugScreenPrintf("\n        [ ENCENDIDO ]    \n");
    } else {
        pspDebugScreenSetTextColor(COLOR_GRIS);
        pspDebugScreenPrintf("           .---.        \n");
        pspDebugScreenPrintf("          /     \\       \n");
        pspDebugScreenPrintf("         |       |      \n");
        pspDebugScreenPrintf("          \\     /       \n");
        pspDebugScreenPrintf("           |===|        \n");
        pspDebugScreenPrintf("           '---'        \n");
        pspDebugScreenSetTextColor(COLOR_BLANCO);
        pspDebugScreenPrintf("\n        [ APAGADO ]      \n");
    }
}

int main(void) {
    pspDebugScreenInit();
    SetupCallbacks();
    
    int foco_encendido = 0;
    
    while(1) {
        dibujar_foco(foco_encendido);
        foco_encendido = !foco_encendido;
        
        sceKernelDelayThread(2000000); 
    }
    
    return 0;
}