#include "main.h"

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
		if (*format == '%')
		{
			format++;
			if (*format == ' ')
			{
				for (; *format != '%'; format++)
				{
				}
			}

			count = print_args1(args, *format, count);
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
