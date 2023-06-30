#include "main.h"
#include <unistd.h>

/**
 * print_hex - prints the hex equivalent of a number
 * @num: the number whose hex value is to be printed
 * @fs: the format specifier (x or X)
 *
 * Return: the number of digits printed
 */

int print_hex(unsigned int num, char fs)
{
	int i, digits;
	char arr[1024];

	if (num == 0)
	{
		return (write(1, "0", 1));
	}

	for (i = 0; num > 0; i++)
	{
		switch (fs)
		{
			case 'x':
				arr[i] = "0123456789abcdef"[num % 16];
				break;
			case 'X':
				arr[i] = "0123456789ABCDEF"[num % 16];
		}
		num /= 16;
	}
	arr[i] = '\0';
	digits = i;
	i--;

	for (; i >= 0; i--)
	{
		write(1, &arr[i], 1);
	}
	return (digits);
}
