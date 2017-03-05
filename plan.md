
# Plan of attack (gracefully stolen from [os-dev](http://wiki.osdev.org/What_order_should_I_make_things_in):

1. Printing to Screen (done in kprint)
2. Serial Out/In
3. Interrupts 
4. Memory Mangement
5. Malloc and free
6. C_lib [os-dev](http://wiki.osdev.org/Porting_Newlib)

## Build a small OS for fun and profit!
Uses a general C/C++ compiler like Clang or gcc, meaning: Kernel is an ELF executable
Loaded by a bootloader like GRUB or U-Boot(as squash-fs?)



Ultimate goal:

- Lua capable
- zsh prompt
- fat32/exfat/ext* compatible fs
- running on cewl hardware like a Rpi or a Z80


calls from xv6:
// System call numbers
#define SYS_fork    1
#define SYS_exit    2
#define SYS_wait    3
#define SYS_pipe    4
#define SYS_read    5
#define SYS_kill    6
#define SYS_exec    7
#define SYS_fstat   8
#define SYS_chdir   9
#define SYS_dup    10
#define SYS_getpid 11
#define SYS_sbrk   12
#define SYS_sleep  13
#define SYS_uptime 14
#define SYS_open   15
#define SYS_write  16
#define SYS_mknod  17
#define SYS_unlink 18
#define SYS_link   19
#define SYS_mkdir  20
#define SYS_close 21

extern int sys_chdir(void);
extern int sys_close(void);
extern int sys_dup(void);
extern int sys_exec(void);
extern int sys_exit(void);
extern int sys_fork(void);
extern int sys_fstat(void);
extern int sys_getpid(void);
extern int sys_kill(void);
extern int sys_link(void);
extern int sys_mkdir(void);
extern int sys_mknod(void);
extern int sys_open(void);
extern int sys_pipe(void);
extern int sys_read(void);
extern int sys_sbrk(void);
extern int sys_sleep(void);
extern int sys_unlink(void);
extern int sys_wait(void);
extern int sys_write(void);
extern int sys_uptime(void);