#include "main.h"

/**
*puts2 - prints every other character of a string,
*starting with the first character, followed by a new line
*@str: string
*return: print
*/

void puts2(char *str)
{
int i;

for (i = 0; i < 10;)
{
	_putchar(*(str + i));
	i++;
	i++;
}
_putchar('\n');
}
