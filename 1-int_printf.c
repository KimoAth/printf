#include "main.h"
#include <limits.h>
/**
 * print_digit - a function that prints a digit
 * @n: the digit
 * @count: the counter
 * Return: count
 */
int print_digit(int n, int count)
{
	count = print_char(n + '0', count);
	return (count);
}
/**
 * print_int - a function that prints a signed decimal int
 * @n: the number
 * @count: the counter
 * Return: count
 */
int print_int(int n, int count)
{
	int num, y, k;

	y = 1000000000;

	if (n == 0)
		count = print_char('0', count);
	else if (n > 0)
		n = -n;
	else
		count = print_char('-', count);
	for (num = 0; num < 10; num++, y /= 10)
	{
		if (n / y == 0)
			continue;
		else
		{
			k = (-(n / y) % 10);
			if (k < 0)
				k *= -1;
			count = print_digit(k, count);
		}
	}
	return (count);
}
/**
 * print_binary - a function that changes a number to binary and then print it
 * @n: the number
 * @count: the counter
 * Return: count
 */
int print_binary(unsigned int n, int count)
{
	int number = n;
	int position = sizeof(unsigned int) * 8 - 1;

	if ((n > UINT_MAX && number < 0))
	{
	count = print_string("(null)", count);
	return (count);
	}
	if (number == 0)
	{
	count = print_digit(0, count);
	return (count);
	}
	while (position >= 0 && !(n & (1 << position)))
	{
	position--;
	}
	while (position >= 0)
	{
		count = print_char(n & (1 << position) ? '1' : '0', count);
		position--;
	}
	return (count);
}

/**
  *print_u - a function that prints an unsigned decimal int
  *@num: the decimal int
  *@count: the counter
  *Return: count
  */
int print_u(unsigned int num, int count)
{
	if (num < 10)
	{
		print_char(num + '0', count);
	}
	else
	{
		count = print_u(num / 10, count);
		count = print_u(num % 10, count);
	}

	return (count);
}

/**
  *print_octal - a function that prints unsigned octal
  *@num: the number
  *@count: the counter
  *Return: count
  */
int print_octal(unsigned int num, int count)
{
	char octal_digits[32];
	int i = 0;

	if (num == 0)
	{
		count = print_char('0', count);
	}
	while (num != 0)
	{
		octal_digits[i++] = num % 8 + '0';
		num /= 8;
	}
	while (i-- > 0)
	{
		count = print_char(octal_digits[i], count);
	}
	return (count);
}
