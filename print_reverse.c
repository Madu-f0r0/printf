#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
* print_reverse - A function that prints a string in reverse.
* @str: string of characters
* Return: characters printed.
*/


int print_reverse(char *str)
{
int i, len = 0, count = 0;
char *ch;
if (str == NULL)
{
write(1, "(null)", 6);
count = 6;
}
else
{
for (i = 0; str[i] != '\0'; i++)
{
count++;
}
ch = malloc((sizeof(char) * i + 1));
if (ch == NULL)
return (0);
for (len = i - 1; len >= 0; len--)
{
ch[i - 1 - len] = str[len];
}
ch[i] = '\0';
write(1, ch, i);
free(ch);
}
return (count);
}
