KERNEL_DIR = kernel
LIBC_DIR = libc
ARCH_SRC_DIR = arch/$(arch)

ASM_SRC := $(wildcard $(ARCH_SRC_DIR)/*.asm)
ASM_OBJS := $(ASM_SRC:$(ARCH_SRC_DIR)/%.asm=$(OBJDIR)/$(arch)/%.o)

C_ARCH_SRC := $(wildcard $(ARCH_SRC_DIR)/*.c)
C_ARCH_OBJS := $(C_ARCH_SRC:$(ARCH_SRC_DIR)/%.c=$(OBJDIR)/$(arch)/%.o)

.PHONY: KERNEL_BIN 
	
KERNEL_BIN: $(ASM_OBJS) $(C_ARCH_OBJS)
	$(MAKE) -C $(LIBC_DIR)
	$(MAKE) -C $(KERNEL_DIR)

$(ASM_OBJS): $(OBJDIR)/$(arch)/%.o : $(ARCH_SRC_DIR)/%.asm
	nasm -felf64 $< -o $@

$(C_ARCH_OBJS): $(OBJDIR)/$(arch)/%.o : $(ARCH_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
