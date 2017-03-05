// From xv6 x86 version or from xinu_86
#include <stdint.h>
#include <stdbool.h>

// uint8_t port_byte_in(unsigned short port){
// 	uint8_t result;
// 	__asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
// 	return result;
// }

// void port_byte_out(uint16_t port, uint8_t data){
// 	__asm__("out %%al, %%dx" : : "a" (data), "d" (port));
// }

// uint16_t port_word_in(uint16_t port){
// 	uint16_t result;
// 	__asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
// 	return result;
// }

// void port_word_out(uint16_t port, uint16_t data){
// 	__asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
// }

static inline void outb(uint16_t port, uint8_t val)
{
    __asm__ volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
    /* There's an outb %al, $imm8  encoding, for compile-time constant port numbers that fit in 8b.  (N constraint).
     * Wider immediate constants would be truncated at assemble-time (e.g. "i" constraint).
     * The  outb  %al, %dx  encoding is the only option for all other cases.
     * %1 expands to %dx because  port  is a uint16_t.  %w1 could be used if we had the port number a wider C type */
}

static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    __asm__ volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}

static inline bool are_interrupts_enabled()
{
    unsigned long flags;
    __asm__ volatile ( "pushf\n\t"
                   "pop %0"
                   : "=g"(flags) );
    return flags & (1 << 9);
}