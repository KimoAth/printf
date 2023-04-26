#include "main.h"
#include <string.h>

/**
 * _printf - simplified version of printf function
 * @format: format string containing conversion specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int len = _strlen(format);
	int i = 0;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	for (; i < len - 1; i++)
	{
		if (format[i] == '%')
		{
			format++;
			if (format[i] == ' ')
			{
				for (; format[i] == ' '; i++)
				{
				}
			}
			count = print_args1(args, format[i], count);
		}
		else
		{
			count = print_char(format[i], count);
		}
	}
	va_end(args);
	if (format[i] == '%')
	{
		count = -1;
	}
	return (count);
}
