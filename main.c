#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len = _printf("string     %        %zzs");
    printf("\n");
    _printf("%d\n", len);
    return (0);
}
