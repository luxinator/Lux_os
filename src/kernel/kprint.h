// #include "kernel.h"
#include <stddef.h>

// int fputc(char c, FILE *fp);

// int putc(char c, FILE *fp);

int kputchar( char c);

// int fgetc( FILE *fp);
// int getc( FILE *fp);
int kgetchar();

// int fputs( const char* s, FILE *fp);
int kputs( const char* s );

// char* fgets( char *s, size_t n, FILE *fp);
char* kgets( char * buffer );

int kprintf(const char * s, ...);