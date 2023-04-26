#include "main.h"
/**
  *print_rot -  prints the rot13'ed string
  *@str: the string
  *@count: the counter
  *Return: the count
  */
int print_rot(char *str, int count)
{
	int i, len;
	char c;
	char rot_up[26] = {"NOPQRSTUVWXYZABCDEFGHIJKLM"};
	char rot_lw[26] = {"nopqrstuvwxyzabcdefghijklm"};

	if (str == NULL)
	{
		count = print_string("(null)", count);
		return (23);
	}
	len = _strlen(str);
	for (i = 0; i < len; i++)
	{
		c = str[i];
		if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		{
			if (c >= 97 && c <= 122)
			{
				c = rot_lw[c - 'a'];
			}
			else
			{
				c = rot_up[c - 'A'];
			}
		}
		count = print_char(c, count);
	}
	return (count);
}
