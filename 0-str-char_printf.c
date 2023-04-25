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
/**
  *print_nstr - a function that prints non printable character
  *@c: the string
  *@count: the count
  *Return: the count
  */
int print_nstr(char *c, int count)
{
	while (*c)
	{
		if (*c < 32 || *c >= 127)
		{
			count += print_char('\\', count);
			count += print_char('X', count);
			if ((*c / 16) < 10)
			{
				count = print_char((*c / 16) + '0', count);
			}
			else
			{
			count = print_char((*c / 16) - 10 + 'A', count);
			}
			if ((*c % 16) < 10)
			{
				count = print_char((*c % 16) + '0', count);
			}
			else
			{
			count = print_char((*c % 16) - 10 + 'A', count);
			}
		}
		else
		{
			count += print_char(*c, count);
		}
		c++;
	}
	return (count);
}
