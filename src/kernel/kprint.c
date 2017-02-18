#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "kprint.h"
#ifdef x86_64
#include <vga_framebuffer.h>

#endif
// FROM XV6 -> from Unix v6 released under BSD license
// Changed by L.M. van Oosterhout
static void printint(int xx, int base, bool sign) {
  static char digits[] = "0123456789abcdef";
  char buf[16];
  int i;
  unsigned int x;

  if (sign && (sign = xx < 0))
    x = -xx;
  else
    x = xx;

  i = 0;
  do {
    buf[i++] = digits[x % base];
  } while ((x /= base) != 0);

  if (sign)
    buf[i++] = '-';

  while (--i >= 0)
    putchar_framebuffer_wob((int)((const unsigned char*)buf)[i]);
}

int kputchar(char c) {
  return 0;
}

// int fgetc( FILE *fp);
// int getc( FILE *fp);
int kgetchar() {
  return 0;
}

// int fputs( const char* s, FILE *fp);
int kputs(const char* s) {
  return 0;
}
// char* fgets( char *s, size_t n, FILE *fp);
char* kgets(char* buffer) {
  return NULL;
}

int kprintf(const char* restrict format, ...) {
  // Variable Parameter list
  va_list parameters;
  va_start(parameters, format);

  while (*format != '\0') {
    // Encounterd a formatter we accept:
    // d, i, f, p, s, c
    if (*format == '%') {
      char specifier = *(format + 1);
      switch (specifier) {
        case 'd':
          printint((int)va_arg(parameters, int), 10, true);
          format++;
          break;
        case 'i':
          printint((int)va_arg(parameters, int), 10, true);
          format++;
          break;
        case 'p':
		  format++;
          write_fb_wob("0x");
          printint((int) va_arg(parameters, int), 16, true);
          break;
        case 's':
          write_fb_wob((char*)va_arg(parameters, char*));
          format++;
          break;
        case 'c':
          putchar_framebuffer_wob((char)va_arg(parameters, int));
          format++;
          break;
        default:
          putchar_framebuffer_wob(*format);
      }
      format++;
    }
    else {
      // If no specifiers found:
      putchar_framebuffer_wob(*format);
      format++;
    }
  }

  va_end(parameters);

  return 0;
}

void clear_console() {
  clear_framebuffer();
}
