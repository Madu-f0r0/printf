#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * print_octal - prints the octal equivalent of a decimal number
 * @num: the number whose octal equivalent is to be printed
 *
 * Return: the number of digits printed
 */

int print_octal(unsigned int num)
{
	int i = 0, digits = 0;
	char arr[1024];

	if (num == 0)
	{
		return (write(1, "0", 1));
	}

	while (num > 0)
	{
		arr[i] = '0' + (num % 8);
		num /= 8;
		i++;
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
