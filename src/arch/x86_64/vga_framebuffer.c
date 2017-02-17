#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "vga_framebuffer.h"
/**
 * The Driver for the x86 vga textwriter
 * Info from:
 * http://littleosbook.github.io/#about-the-book
 * http://os.phil-opp.com/printing-to-screen.html
 */

#define FB_START 0xB8000
#define FB_WIDTH 80
#define FB_HEIGHT 25

// Any Char in the frameBuffer is 16-bits wide (from
// http://littleosbook.github.io/)
// Bit:     | 15 14 13 12 11 10 9 8 | 7 6 5 4 | 3 2 1 0 |
// Content: | ASCII                 | FG      | BG      |

uint16_t* frameBuffer = (uint16_t*)FB_START;

size_t x = 0, y = 0;

void write_char_fb(size_t loc,
                   char c,
                   enum framebuffer_color fg,
                   enum framebuffer_color bg) {
  uint16_t c16 = c;
  frameBuffer[loc] = c16 | (fg | bg << 4) << 8;
}

void scroll_up_fb(){
	for(size_t i = 0; i < FB_HEIGHT; i++){
    memcpy(frameBuffer +i * FB_WIDTH, frameBuffer + (i+1) * FB_WIDTH, FB_WIDTH);
  }
  y -= 2;
}

void clear_framebuffer() {
  for (uint16_t i = 0; i < FB_HEIGHT * FB_WIDTH; i++) {
    frameBuffer[i] = (uint16_t)0;
  }
}

void write_line_fb(const char* line,
                   enum framebuffer_color fg,
                   enum framebuffer_color bg) {

  for (size_t i = 0; i < strlen(line); i++) {
    write_char_fb(y * FB_WIDTH + x, line[i], fg, bg);
    //Move a posistion to the right
    if(++x == FB_WIDTH){
    	// Auto Break Line
    	if(++y == FB_HEIGHT){
    		//We reached the bottom:
    		scroll_up_fb();
    	}
      x = 0;
    }
  }
}

void write_line_fb_wob(const char *line){
	write_line_fb(line, WHITE, BLACK);
}