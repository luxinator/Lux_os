#include "kprint.h"
#include <multiboot2.h>

extern void *start;

void kmain(void *mutlibootAdress) {

  clear_console();
#ifdef _DO_TESTS
  kprintf("Print Test:\n");
  kprintf("Hello World! %c%c%c, %s\n\t%d %p\r:D", 'a', 'b', 'c', "more %s!",
          123565432, (kmain));
#endif
  kprintf("Loaded at: %p\n", start);

  // HANG
  kputs("Halting...");
  while (1) {
  };
}