/**
 * The Driver for the x86 vga textwriter
 * Info from: 
 * http://littleosbook.github.io/#about-the-book
 * http://os.phil-opp.com/printing-to-screen.html
 */
#ifndef VGA_BUFFER_H_
#define VGA_BUFFER_H_

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

void write_fb(const char* data,
                   enum framebuffer_color fg,
                   enum framebuffer_color bg);

void write_fb_wob(const char *data);

void putchar_framebuffer(const char c,
             enum framebuffer_color fg,
             enum framebuffer_color bg);


void putchar_framebuffer_wob(const char c);

#endif