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
	va_list args;

	va_start(args, format);
	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				write(STDOUT_FILEN, "%", 1);
				count++;
			}
			else if (*format == 'c')
			{
				int ch = va_arg(args, int);

				write(STDOUT_FILENO, &ch, 1);
				count++;
			}
			else if (*forma == 's')
			{
				char *str = va_arg(args, char *);
				int len = strlen(str);

				write(STDOUT_FILENO, str, len);
				count += len;
			}
		}
		else
		{
			write(STDOUT_FILENO, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
/**
 * main - entry point
 * Return: nothing
 */
int main(void)
{
	_printf("The man who score Grade %c, is %s\n", 'A', "James");
	return (0);
}
