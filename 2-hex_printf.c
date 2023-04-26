#include "main.h"
/**
  *print_hex - a function that printscUnsigned hexadecimal integer (lowercase)
  *@num: the number parameter
  *@count: the counter
  *Return: count
  */
int print_hex(unsigned int num, int count)
{
	char hexadecimal_num[100];
	int i = 0;
	int j;

	while (num != 0)
	{
		int remainder = num % 16;

		if (remainder < 10)
			hexadecimal_num[i] = remainder + '0';
		else
			hexadecimal_num[i] = remainder + 'a' - 10;
		num /= 16;
		i++;
	}
	if (i == 0)
	{
		count = print_char('0', count);
	}
	else
	{
		for (j = i - 1; j >= 0; j--)
		{
			count = print_char(hexadecimal_num[j], count);
		}
	}
	return (count);
}
/**
 *print_hex_upper - a function prints Unsigned hexadecimal integer (uppercase)
 *@num: the number parameter
 *@count: the counter
 *Return: count
*/
int print_hex_upper(unsigned int num, int count)
{
	char hexadecimal_num[100];
	int i = 0;
	int j;

	while (num != 0)
	{
		int remainder = num % 16;

		if (remainder < 10)
			hexadecimal_num[i] = remainder + '0';
		else
			hexadecimal_num[i] = remainder + 'A' - 10;
		num /= 16;
		i++;
	}
	if (i == 0)
	{
		count = print_char('0', count);
	}
	else
	{
		for (j = i - 1; j >= 0; j--)
		{
			count = print_char(hexadecimal_num[j], count);
		}
	}
	return (count);
}

/**
  *print_pointer - a function that print a pointer address
  *@ptr: the pointer
  *@count: the counter
  *Return: the count
  */
int print_pointer(void *ptr, int count)
{
	char hex_digits[] = "0123456789abcdef";
	unsigned long address = (unsigned long)ptr;
	int i = (sizeof(address) * 2) - 1;
	int found_nonzero = 0;

	if (ptr == NULL)
	{
		count = print_string("(nil)", count);
		return (count);
	}
	write(1, "0x", 2);
	count += 2;
	for (; i >= 0; i--)
	{
		char hex_char = hex_digits[(address >> (i * 4)) & 0xf];

		if (hex_char != '0' || found_nonzero || i == 0)
		{
			found_nonzero = 1;
			write(1, &hex_char, 1);
			count++;
		}
	}
	return (count);
}
