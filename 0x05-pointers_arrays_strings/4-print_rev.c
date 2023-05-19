#include "main.h"

/**
* print_rev - prints a string, in reverse, followed by a new line.
* @s: the string
*/

void print_rev(char *s)
{
	int len;

	for (len = 0; *(s + len) != '\0'; len++)
	{
		;
	}
	for (; len >= 0; len--)
	{
		_putchar (*(s + len));
	}
	_putchar ('\n');


}
