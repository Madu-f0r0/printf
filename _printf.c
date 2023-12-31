#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

/**
 * _printf - prints anything passed
 * @format: the string to be printed
 *
 * Return: the number of bytes printed
 */

int _printf(const char *format, ...)
{
	int i, caseReturn, elementCount = 0;
	int nbuff;
	unsigned int ubuff;
	char cbuff;
	char *sbuff;
	char *spbuff;
	va_list elements;
	char *revbuff;

	va_start(elements, format);

	if (format == NULL)
	{
		return (-1);
	}

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					cbuff = va_arg(elements, int);
					print_char(cbuff);
					elementCount++;
					break;
				case 's':
					sbuff = va_arg(elements, char *);
					caseReturn = print_string(sbuff);
					elementCount += caseReturn;
					break;
				case '%':
					write(1, "%", 1);
					elementCount++;
					break;
				case 'd':
					nbuff = va_arg(elements, int);
					caseReturn = print_number(nbuff);
					elementCount += caseReturn;
					break;
				case 'i':
					nbuff = va_arg(elements, int);
					caseReturn = print_number(nbuff);
					elementCount += caseReturn;
					break;
				case 'b':
					ubuff = va_arg(elements, unsigned int);
					caseReturn = binary(ubuff);
					elementCount += caseReturn;
					break;
				case 'S':
					spbuff = va_arg(elements, char *);
					caseReturn = print_custom_string(spbuff);
					elementCount += caseReturn;
					break;
				case 'r':
					revbuff = va_arg(elements, char *);
					caseReturn = print_reverse(revbuff);
					elementCount += caseReturn;
					break;
				case 'u':
					ubuff = va_arg(elements, unsigned int);
					caseReturn = print_unsigned(ubuff);
					elementCount += caseReturn;
					break;
				case 'o':
					ubuff = va_arg(elements, unsigned int);
					caseReturn = print_octal(ubuff);
					elementCount += caseReturn;
					break;
				case 'x':
					ubuff = va_arg(elements, unsigned int);
					caseReturn = print_hex(ubuff, 'x');
					elementCount += caseReturn;
					break;
				case 'X':
					ubuff = va_arg(elements, unsigned int);
					caseReturn = print_hex(ubuff, 'X');
					elementCount += caseReturn;
					break;
				case '\0':
					return (-1);
				default:
					write(1, &format[i - 1], 1);
					write(1, &format[i], 1);
					elementCount += 2;
			}

		}
		else
		{
			write(1, &format[i], 1);
			elementCount++;
		}
	}
	return (elementCount);
}
