#include <pspkernel.h>
#include <pspdebug.h>

// Configuración del módulo del PSP
PSP_MODULE_INFO("HelloWorld", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

int main(void) {
    // Inicializar la pantalla del PSP
    pspDebugScreenInit();
    
    // Imprimir en las coordenadas (0,0) por defecto
    pspDebugScreenPrintf("Hello World!\n");
    pspDebugScreenPrintf("Mi primer programa en PSP.\n");

    // Pausar el hilo principal para que la aplicación no se cierre sola
    sceKernelSleepThread();
    
    return 0;
}