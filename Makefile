TARGET = helloworld

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

CFLAGS   = -O2 -G0 -Wall -Iinclude
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS  = $(CFLAGS)

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = ControlCruceta

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak