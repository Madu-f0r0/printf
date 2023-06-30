#include <unistd.h>
#include <stdlib.h>
/**
* print_custom_string- function that prints non printable character.
* @str: string of characters.
* Return: Characters printed.
*/


int print_custom_string(char *str)
{
int i, count = 0;
if (str == NULL)
{
write(1, "(null)", 6);
count = 6;
}

for (i = 0; str[i] != '\0'; i++)
{
if (str[i] < 32 || str[i] >= 127)
{
char hex[4] = {'\\', 'x', '0', '0'};
unsigned char ch = (unsigned char)str[i];
hex[2] = "0123456789ABCDEF"[ch / 16];
hex[3] = "0123456789ABCDEF"[ch % 16];
write(1, hex, 4);
count = count + 4;
}
else
{
write(1, &str[i], 1);
count++;
}
}
return (count);
}
