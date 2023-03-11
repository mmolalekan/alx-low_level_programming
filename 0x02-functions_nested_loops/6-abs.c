#include "main.h"

/**
* _abs - computes the absolute value of an integer
* @n: int to be tested
* Return: the absolute value of int
*/

int _abs(int n)
{
	if (n <= 0)
	{
		return (-n);
		_putchar('\n');
	}
	else
	{
		return (n);
		_putchar('\n');
	}
}
