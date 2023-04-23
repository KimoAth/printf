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
		default:
		break;
	}
	return (count);
}
