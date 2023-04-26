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
		count = print_string("(null)", count);
		return (count);
	}
	while (*str)
	{
		count = print_char(*str, count);
		str++;
	}
	if (*str == '\0' && *(str - 1) == '%')
	{
		count = -1;
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
	if (c == NULL || c == 0)
	{
		return (print_string("(null)", count));
	}
	while (*c != '\0')
	{
		if (*c < 32 || *c >= 127)
		{
			count = print_char('\\', count);
			count = print_char('x', count);
			count = print_char((*c / 16) + '0', count);
			count = print_char((*c % 16) + ((*c % 16 < 10) ? '0' : 'A' - 10), count);
		}
		else
		{
			count = print_char(*c, count);
		}
		c++;
	}
	return (count);
}
/**
  *print_rev - a function print a string in reverse
  *@str: the string
  *@count: the counter
  *Return: the counter
  */
int print_rev(char *str, int count)
{
	int i = _strlen(str);
	int j;

	if (str == 0)
	{
		count = print_string("(null)", count);
		return (count);
	}

	for (j = i - 1; j >= 0; j--)
	{
		count = print_char(str[j], count);
	}
	return (count);
}
/**
  *_strlen - a function behave like strlen
  *@str: the string we counting
  *Return: count
  */
int _strlen(const char *str)
{
	int counter = 0;

	while (*str != '\0')
	{
		counter++;
		str++;
	}
	return (counter);
}
