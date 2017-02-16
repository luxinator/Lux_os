
CFLAGS:=$(CFLAGS) -ffreestanding -fbuiltin 
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc

SOURCES  := $(wildcard *.c)
INCLUDES := $(wildcard *.h)
# OBJDIR = ../build
OBJECTS  := $(SOURCES:%.c=$(OBJDIR)/%.o)

$(OBJECTS): $(OBJDIR)/%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

