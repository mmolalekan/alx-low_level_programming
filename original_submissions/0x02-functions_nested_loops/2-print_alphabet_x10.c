#include "main.h"
/**
*print_alphabet_x10 - rints 10 times the alphabet, in lowercase
*/

void print_alphabet_x10(void)
{
char letter;
int i = 1;

	while (i <= 10)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
		{
			_putchar(letter);
		}
		i++;
		_putchar('\n');
	}
}
