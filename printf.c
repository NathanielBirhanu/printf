#include "main.h"
/**
 * _printf - function that produces output according to a format.
 * @format: a list of types of arguments passed to the function
 *
 * Return: number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				write(STDOUT_FILENO, "%", 1); count++;
			}
			else if (*format == 'c')
			{
				int ch = va_arg(args, int);

				write(STDOUT_FILENO, &ch, 1); count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				int len = strlen(str);

				write(STDOUT_FILENO, str, len); count += len;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int x = va_arg(args, int);
				char str[32];
				int len = sprintf(str, "%d", x);

				write(STDOUT_FILENO, str, len); count += len;
			}
		}
		else
		{
			write(STDOUT_FILENO, format, 1); count++;
		}
		format++;
	}
	va_end(args); return (count);
}
