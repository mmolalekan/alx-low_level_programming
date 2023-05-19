#include "main.h"

/**
* puts_half - prints half of a string, followed by a new line.
* @str: string to be printed
*/

void puts_half(char *str)
{
	int len, i;

	for (len = 0; *(str + len) != '\0'; len++)
	{
		;
	}
	if ((len % 2) == 0)
	{
		for (i = 0; *(str + (len / 2) + i) != '\0'; i++)
		{
			_putchar (*(str + (len / 2) + i));
		}
		_putchar ('\n');
	}
	else
	{
		for (i = 0; *(str + ((len - 1) / 2) + i) != '\0'; i++)
		{
			_putchar (*(str + ((len - 1) / 2) + i));
		}
		_putchar ('\n');
	}
}
