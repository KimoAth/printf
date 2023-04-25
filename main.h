#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int print_char(char c, int count);
int print_int(int n, int count);
int print_string(char *str, int count);
int print_digit(int n, int count);
int print_binary(unsigned int n, int count);
int print_nstr(char *c, int count);
int print_args1(va_list args, char specifier, int count);
int _printf(const char *format, ...);
#endif
