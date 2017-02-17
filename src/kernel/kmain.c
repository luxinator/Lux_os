#include <vga_framebuffer.h>

void kmain(){
	
	clear_framebuffer();
	write_line_fb("LOL", WHITE, BLACK);
	uint8_t i = 0;
	while(1){
		// write_line_fb("LOL", RED, BLACK);
		write_line_fb("LOL", WHITE, BLACK);
		// write_line_fb(&i, WHITE, BLACK);
		for(int j = 0; j < 1000000; j++){

		}
		i++;
	}
}

