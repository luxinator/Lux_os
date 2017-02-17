/**
 * The Driver for the x86 vga textwriter
 * Info from: 
 * http://littleosbook.github.io/#about-the-book
 * http://os.phil-opp.com/printing-to-screen.html
 */
#include <stdint.h>
#include <stddef.h>

enum framebuffer_color
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GREY = 7,
	DARK_GREY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	LIGHT_BROWN = 14,
	WHITE = 15,
};

void write_char_fb(size_t loc,
                   char c,
                   enum framebuffer_color fg,
                   enum framebuffer_color bg);

void clear_framebuffer();

void write_line_fb(const char* line,
                   enum framebuffer_color fg,
                   enum framebuffer_color bg);

void write_line_fb_wob(const char *line);

// static inline uint8_t make_color(enum vga_color fg, enum vga_color bg)
// {
// 	return fg | bg << 4;
// }

// static inline uint16_t make_vgaentry(char c, uint8_t color)
// {
// 	uint16_t c16 = c;
// 	uint16_t color16 = color;
// 	return c16 | color16 << 8;
// }