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

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == ' ')
			{
				for (; *format != '%' && *format != '\0'; format++)
				{
					count = print_args1(args, *format, count);
				}
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
	if (format[len] == '\0' && format[len - 1] == '%')
		count = -1;
	return (count);
}
