
CFLAGS:=$(CFLAGS) -ffreestanding -fbuiltin 
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc

SOURCES  := $(wildcard *.c)
INCLUDES := $(wildcard *.h)
# OBJDIR = ../build
export K_OBJECTS  := $(SOURCES:%.c=$(OBJDIR)/%.o)

$(K_OBJECTS): $(OBJDIR)/%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

