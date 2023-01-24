#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
*_printf - prints different types of string formats
*@format: string input to function
*Return: integer
*/

int _printf(const char *format, ...)
{
va_list args;
int i, count  = 0;
char *s = NULL;
char error_msg[] = "Unknown format specifier: %";

va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
i++;
switch (format[i])
{
case 'c':
_putchar(va_arg(args, int));
count++;
break;

case 's':
while (*s != '\0')
count += _puts(va_arg(args, char *));
break;

case '%':
_putchar('%');
count++;
break;

case 'r':
while (*s != '\0')
count += print_rev(va_arg(args, char *));
break;
default:
if (format[i] != 'c' && format[i] != 's' && format[i] != '%')
_puts(error_msg);
_putchar(format[i]);
_putchar('\n');
va_end(args);
exit(1);
break;
}
_putchar(format[i]);
count++;
va_end(args);
}
return (count);
}
