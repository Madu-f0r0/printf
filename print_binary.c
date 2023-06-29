#include "main.h"
#include <unistd.h>

/**
 * binary - prints the binary equivalent of a decimal number
 * @num: the number whose binary equivalent is to be printed
 *
 * Return: the number of digits printed
 */

int binary(unsigned int num)
{
	int i = 0, digits = 0;
	char arr[1024];

	if (num > 1)
	{
		while (num > 1)
		{
			arr[i] = '0' + (num % 2);
			num /= 2;
			i++;
		}
		arr[i++] = '1';
	}
	else
	{
		arr[i++] = '0' + num;
	}
	arr[i] = '\0';
	digits = i;
	i--;

	while (i >= 0)
	{
		write(1, &(arr[i]), 1);
		i--;
	}
	return (digits);
}
