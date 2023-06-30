#include "main.h"
#include <stdlib.h>
#include <unistd.h>

int print_unsigned(unsigned int num);

/**
 * print_unsigned - prints an unsigned int passed as argument
 * @num: the number to be printed
 *
 * Return: the number of digits printed plus sign if present
 */

int print_unsigned(unsigned int num)
{
	int digitCount = 0, i = 0;
	unsigned int dupNum;
	char *arr;

	if (num == 0)
	{
		write(1, "0", 1);
		digitCount++;
	}
	else
	{
		/* Calculate no of digits the number has */
		dupNum = num;
		while (dupNum != 0)
		{
			dupNum = dupNum / 10;
			digitCount++;
		}

		/* Create char array for the digits */
		arr = malloc(sizeof(char) * (digitCount));
		if (arr == NULL)
		{
			return (0);
		}

		/* Split number into digits and pass to char array */
		while (num != 0)
		{
			arr[i] = '0' + (num % 10);
			num = num / 10;
			i++;
		}

		/* Write digits to stdout */
		for (i = (digitCount - 1); i >= 0; i--)
		{
			write(1, &arr[i], 1);
		}
	}

	/* Return no of digits printed */
	return (digitCount);
}
