#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

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

/**
 *print_int - prints integers
 *@n: integer
 *Return: number of characters
 */

int print_int(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		count++;
	}
	if (n / 10)
	{
		count += print_int(n / 10);
	}
	_putchar(n % 10 + '0');
	count++;
	return (count);
}

/**
*_printf - prints different types of string formats
*@format: string input to function
*Return: integer
*/

int _printf(const char *format, ...)
{
	int i, count = 0;
	char error_msg[] = "Unknown format specifier: %";
	va_list arg;

	va_start(arg, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				count += _putchar(va_arg(arg, int));
				break;

			case 's':
				count += _puts(va_arg(arg, char *));
				break;

			case '%':
				count += _putchar('%');
				break;
			case 'i':
			case 'd':
				count += print_int(va_arg(arg, int));
				break;
			default:
				_puts(error_msg);
				_putchar(format[i]);
				break;
			}
		}
		else

			_putchar(format[i]);

	}
	va_end(arg);
	return (count);
}
