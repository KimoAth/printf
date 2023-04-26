#include "main.h"
/**
  *print_hex - a function that printscUnsigned hexadecimal integer (lowercase)
  *@num: the number parameter
  *@count: the counter
  *Return: count
  */
int print_hex(unsigned int num, int count)
{
	char HEX_CHARS[100];
	int i = 0;
	int j;

	while (num != 0)
	{
		int remainder = num % 16;

		if (remainder < 10)
		       	HEX_CHARS[i] = remainder + '0';
		else
			HEX_CHARS[i] = remainder + 'a' - 10;
		num /= 16;
		i++;
	}
	if (i == 0)
	{
		print_char('0', count);
		count++;
	}
	else
	{
		for (j = i - 1; j >= 0; j--)
		{
            		print_char(HEX_CHARS[j], count);
            		count++;
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
	char hex_digits[100];
	int i = 0;
	int j;

	while (num != 0)
	{
		int remainder = num % 16;

		if (remainder < 10)
			hex_digits[i] = remainder + '0';
		else
			hex_digits[i] = remainder + 'A' - 10;
		num /= 16;
		i++;
	}
	if (i == 0)
	{
		print_char('0', count);
		count++;
	}
	else
	{
		for (j = i - 1; j >= 0; j--)
		{
			print_char(hex_digits[j], count);
			count++;
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
void print_pointer(void *ptr, int count)
{
	int i;
	int hex_digit;
	int printed_prefix = 0;
	unsigned long int address;

	if (ptr == NULL)
	{
		count = print_string("(nil)", count);
		return (count);
	}
	address = (unsigned long int)ptr;
	print_char('0', count);
	print_char('x', count);
	count += 2;
	for (i = (sizeof(void ) 2) - 1; i >= 0; i--)
	{
		hex_digit = (address >> (i * 4)) & 0xf;
		if (hex_digit || printed_prefix)
		{
			print_char(hex_digit < 10 ? '0' + hex_digit : 'a' + (hex_digit - 10), count);
			printed_prefix = 1;
			count++;
		}
	}
	if (!printed_prefix)
	{
		print_char('0', count);
		count++;
	}
	return (count);
