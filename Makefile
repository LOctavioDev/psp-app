# Makefile
TARGET = helloworld
OBJS = main.o

CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

# Esto le dice al compilador que genere un EBOOT.PBP
EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Mi Primer Hello World

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak