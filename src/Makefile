KERNEL_DIR = kernel
LIBC_DIR = libc

ASM_SRC_DIR = arch/$(arch)
ASM_SRC := $(wildcard $(ASM_SRC_DIR)/*.asm)
ASM_OBJS := $(ASM_SRC:$(ASM_SRC_DIR)/%.asm=$(OBJDIR)/$(arch)/%.o)


.PHONY: KERNEL_BIN LIBC

KERNEL_BIN: $(ASM_OBJS)
	$(MAKE) -C $(KERNEL_DIR)

LIBC_DIR:
	$(MAKE) -C $(LIBC_DIR)

$(ASM_OBJS): $(OBJDIR)/$(arch)/%.o : $(ASM_SRC_DIR)/%.asm
	nasm -felf64 $< -o $@
