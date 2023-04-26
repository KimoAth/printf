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

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	for (; *format; format++)
	{
		if (*format == '%' || *format == '%')
		{
			format++;
			if (*format == ' ')
			{
				for (; *format != '%' && *format != '\0'; format++)
				{
					count = print_args1(args, *format, count);
				}
			/*	if ((*(format - 1) != '%' ||  (*format == ' ')))
				{
					count = -1;
				}*/
				return (count);
			}
			else
			{
			count = print_args1(args, *format, count);
			}
		}
		else
		{
			print_char(*format, count);
			count++;
		}
	}
	va_end(args);
	return (count);
}
