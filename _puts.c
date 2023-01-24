#include "main.h"

/**
*_puts - prints strings
*@s: string input
*Return: integer output
*/

int _puts(char *s)
{
int count = 0;
while (*s != '\0')
{
_putchar(*s);
s++;
count++;
}
return (count);
}
