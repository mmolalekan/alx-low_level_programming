#include "main.h"

/**
* print_triangle - prints a triangle, followed by a new line.
* @size: the number of times the character \ to be printed
*/

void print_triangle(int size)
{
	int a, space, symbol;

	if (size == 0 || size < 0)
	{
		_putchar ('\n');
		return;
	}
	else
	{
		for (a = 0; a < size; a++)
		{
			for (space = 1; space < size - a; space++)
			{
				_putchar (' ');
			}
			for (symbol = 0; symbol <= a; symbol++)
			{
				_putchar ('#');
			}
		_putchar ('\n');
		}
	}
}
