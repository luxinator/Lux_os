
CFLAGS:=$(CFLAGS) -ffreestanding -fbuiltin 
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc

SOURCES  := $(wildcard *.c)
INCLUDES := $(wildcard *.h)
# OBJDIR = ../build
export L_OBJECTS  := $(SOURCES:%.c=$(OBJDIR)/%.o)


# %.o: %.c $(OBJECTS)
# 	$(CC) -c $< -o $@ -std=gnu11 $(CFLAGS) $(CPPFLAGS)


$(L_OBJECTS): $(OBJDIR)/%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

