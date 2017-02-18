
CFLAGS:=$(CFLAGS)
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc

SOURCES  := $(wildcard *.c)
INCLUDES := $(wildcard *.h)
# OBJDIR = ../build
LOBJECTS  := $(SOURCES:%.c=$(OBJDIR)/%.o)
LIBKC 	:= $(OBJDIR)/libc_k.a

$(LIBKC): $(LOBJECTS)
	$(AR) rcs $@ $(LOBJECTS)

$(LOBJECTS): $(OBJDIR)/%.o : %.c
	$(CC)  -c $< -o $@ $(CFLAGS)
	

