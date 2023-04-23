#include "main.h"

/**
 * _printf - simplified version of printf function
 * @format: format string containing conversion specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	char *per1 = "csiduxXop%";
	int i = 0;
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
					if (*format == '\0')
						return (-1);
				}
			}
			for (; per1[i] != '\0'; i++)
			{
				if (per1[i] == *format)
				{
					count = print_args1(args, *format, count);
				}
			}
			i = 0;
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
