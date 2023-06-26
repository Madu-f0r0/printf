#include "main.h"
#include <unistd.h>

int print_char(char c);

/**
* print_char- A function that prints characters.
*@c: Character to print.
* Return: characters printed.
*/

int print_char(char c)
{
return (write(1, &c, 1));
}

/**
* print_string- A function that print string ofcharacters.
*@str: array of strings.
* Return: characters printed.
*/

int print_string(char *str)
{
int i, count = 0;

if (str == NULL)
{
write(1, "(null)", 6);
count = 6;
}
else
{
for (i = 0; str[i] != '\0'; i++)
{
write(1, &str[i], 1);
count++;
}
}
return (count);
}
