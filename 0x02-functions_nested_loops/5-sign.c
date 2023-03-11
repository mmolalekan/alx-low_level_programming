#include "main.h"

/**
* print_sign - prints the sign of a number.
*@n: argument to check
*return: 1 and prints +, when n is greater than zero
*/

int print_sign(int n)
{

	if (n > 0)
	{
		_putchar('+');
		return (1);
		_putchar('\n');
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
		_putchar('\n');
	}
	else
	{
		_putchar('-');
		return (-1);
		_putchar('\n');
	}
}
