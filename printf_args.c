#include "main.h"
/**
  *print_args1 - a function that detects and do a specific action
  *@args: a parameter
  *@specifier: the character we checking
  *@count: the count
  *Return: count
  */
int print_args1(va_list args, char specifier, int count)
{
	switch (specifier)
	{
		case 'c':
			count = print_char(va_arg(args, int), count);
		break;
		case 's':
			count = print_string(va_arg(args, char *), count);
		break;
		case 'i':
		case 'd':
			count = print_int(va_arg(args, int), count);
		break;
		case 'u':
			count = print_u(va_arg(args, unsigned int), count);
		break;
		case 'x':
			count = print_hex(va_arg(args, unsigned int), count);
		break;
		case 'X':
			count = print_hex_upper(va_arg(args, unsigned int), count);
		break;
		case 'o':
			count = print_octal(va_arg(args, unsigned int), count);
		break;
		case 'b':
			count = print_binary(va_arg(args, unsigned int), count);
		break;
		case '%':
			count = print_char('%', count);
		break;
		case 'S':
			count = print_nstr(va_arg(args, char *), count);
		break;
		default:
			count = print_char('%', count);
			count = print_char(specifier, count);
		break;
	}
	return (count);
}
