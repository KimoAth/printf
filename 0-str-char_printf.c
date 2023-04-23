#include "main.h"
/**
 * print_char - prints a single character to stdout
 * @c: character to print
 *@count: the counter
 *Return: count
 */
int print_char(char c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

/**
 * print_string - prints a string to stdout
 *@str: string to print
 *@count: the counter
 *Return: count
 */
int print_string(char *str, int count)
{
	if (str == NULL || str == 0)
	{
		return (print_string("(null)", count));
	}
	while (*str)
	{
		count = print_char(*str, count);
		str++;
	}
	return (count);
}
