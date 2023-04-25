#include "main.h"
/**
  *print_hex - a function that printscUnsigned hexadecimal integer (lowercase)
  *@num: the number parameter
  *@count: the counter
  *Return: count
  */
int print_hex(unsigned int num, int count)
{
	char HEX_CHARS[] = "0123456789abcdef";
        char hex[8];
        int i = 0;
        int j;

	if (num == 0)
	{
		count = print_char('0', count);
	}
        while (num)
        {
                hex[i++] = HEX_CHARS[num % 16];
                num /= 16;
        }
        hex[i] = '\0';

        for (j = i - 1; j >= 0; j--)
        {
        	count = print_char(hex[j], count);
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
        char hex_digits[] = "0123456789ABCDEF";
        char hex[8];
        int i = 0;
        int j;

        if (num == 0)
        {
                count = print_char('0', count);
        }
	while (num)
        {
                hex[i++] = hex_digits[num % 16];
                num /= 16;
        }
        hex[i] = '\0';

        for (j = i - 1; j >= 0; j--)
        {
        count = print_char(hex[j], count);
        }
        return (count);
}
