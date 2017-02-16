export arch = x86_64
export OBJDIR:= $(PWD)/build
export SRCDIR := src
export INCLUDES := src
kernel := build/kernel-$(arch).bin
iso := build/os-$(arch).iso


export CFLAGS = -O2 -g -Wall -Wextra
linker_script = src/linker.ld
grub_cfg := arch/$(arch)/grub.cfg

$(kernel): init OBJECTS


.PHONY: init 
init:
	@mkdir -p build/
	@mkdir -p build/$(arch)
	
.PHONY: OBJCETS
OBJECTS:
	$(MAKE) -C $(SRCDIR)

clean:
	@rm -r build