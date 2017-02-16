
CFLAGS:=$(CFLAGS) -ffreestanding -fbuiltin 
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc

SOURCES  := $(wildcard *.c)
INCLUDES := $(wildcard *.h)
# OBJDIR = ../build
OBJECTS  := $(SOURCES:%.c=$(OBJDIR)/%.o)


# %.o: %.c $(OBJECTS)
# 	$(CC) -c $< -o $@ -std=gnu11 $(CFLAGS) $(CPPFLAGS)


$(OBJECTS): $(OBJDIR)/%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

