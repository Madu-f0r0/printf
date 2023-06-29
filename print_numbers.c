#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int print_number(int num);

/**
 * print_number - prints a number passed as argument
 * @num: the number to be printed
 *
 * Return: the number of digits printed plus sign if present
 */

int print_number(int num)
{
	int digitCount = 0, i = 0;
	unsigned int absNum, dupAbsNum, negSign = 0;
	char *arr;

	if (num == 0)
	{
		write(1, "0", 1);
		digitCount++;
	}
	else
	{
		/* Get absolute value of the number */
		if (num < 0)
		{
			absNum = (-1) * num;
			write(1, "-", 1);
			negSign = 1;
		}
		else
		{
			absNum = num;
		}

		/* Calculate no of digits the number has */
		dupAbsNum = absNum;
		while (dupAbsNum != 0)
		{
			dupAbsNum = dupAbsNum / 10;
			digitCount++;
		}

		/* Create char array for the digits */
		arr = malloc(sizeof(char) * (digitCount));
		if (arr == NULL)
		{
			return (0);
		}

		/* Split number into digits and pass to char array */
		while (absNum != 0)
		{
			arr[i] = '0' + (absNum % 10);
			absNum = absNum / 10;
			i++;
		}

		/* Write digits to stdout */
		for (i = (digitCount - 1); i >= 0; i--)
		{
			write(1, &arr[i], 1);
		}
	}

	/* Return no of digits printed plus sign (for negative number) */
	return (negSign + digitCount);
}
