#include <vga_framebuffer.h>

void kmain(){
	
	clear_framebuffer();
	write_line_fb("LOL", WHITE, BLACK);
	int i = 0;
	while(1){
		write_line_fb(&i, RED, BLACK);
		i++;
	}
}

