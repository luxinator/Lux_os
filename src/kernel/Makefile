
CFLAGS:=$(CFLAGS) -ffreestanding -fbuiltin 
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc

SOURCES  := $(wildcard *.c)
INCLUDES := $(wildcard *.h) $(wildcard ../arch/$(arch)/*.h)
INCDIR := -I../arch/$(arch)/ -I../libc/
# OBJDIR = ../build
K_OBJECTS  := $(SOURCES:%.c=$(OBJDIR)/%.o)

.PHONY: KERNEL

KERNEL: $(K_OBJECTS)

$(K_OBJECTS): $(OBJDIR)/%.o : %.c
	@$(CC) -c $< -o $@ $(CFLAGS) $(INCDIR) 

