#include "main.h"
/**
* print_alphabet - prints alphabets in lowercase followed by a newline
*/

void print_alphabet(void)
{
	char c;

	for (c = 'a'; c >= 'a' && c <= 'z'; c++)
	{
		_putchar(c);
	}
	_putchar('\n');
}
