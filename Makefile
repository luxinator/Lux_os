export arch = x86_64

export OBJDIR:= $(PWD)/build
export SRCDIR := src
export INCLUDES := src
export CFLAGS = -g -Wall -Wextra
LDFLAGS := 
LIBS := $(LIBS) -nostdlib


kernel := build/kernel-$(arch).bin
iso := build/os-$(arch).iso

linker_script = src/linker.ld
grub_cfg := src/arch/$(arch)/grub.cfg


ALL_OBJECTS = $(wildcard build/*.o) $(wildcard build/$(arch)/*.o)


.PHONY: all clean run iso

$(kernel): init OBJECTS
	ld -n -gc-sections -T $(linker_script) $(LIBS) -o $(kernel) $(ALL_OBJECTS)

run: $(iso)
	@qemu-system-x86_64 -cdrom $(iso)

iso: $(iso)

$(iso): $(kernel)
	@mkdir -p build/isofiles/boot/grub
	@cp $(kernel) build/isofiles/boot/kernel.bin
	@cp $(grub_cfg) build/isofiles/boot/grub
	@grub-mkrescue -o $(iso) build/isofiles 2> /dev/null
	@rm -r build/isofiles

.PHONY: init 
init:
	@mkdir -p build/
	@mkdir -p build/$(arch)
	
.PHONY: OBJCETS
OBJECTS:
	$(MAKE) -C $(SRCDIR)

clean:
	@rm -r build