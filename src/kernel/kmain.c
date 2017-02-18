#include "kprint.h"

void kmain() {

  clear_console();

  kprintf("Print Test:\n");
  kprintf("Hello World! %c%c%c, %s\n\t%d %p\r:D", 'a','b','c', "more %s!", 123565432, (kmain));

  while(1){
  };
  
}
