#include "main.h"

/**
* print_times_table - prints the n times table, starting with 0
* @n: the sumber of times table to be printed
*/

void print_times_table(int n)
{
	int a, b, c, mul;

	if (n > 15 || n < 0)
		return;
	for (a = 0; a <= n; a++)
	{
		for (b = 0; b <= n; b++)
		{
			mul = a * b;
			if (mul <= 9)
				_putchar (mul + '0');
			if (mul > 9 && mul < 100)
			{
				_putchar (mul / 10 + '0');
				_putchar (mul % 10 + '0');
			}
			if (mul > 99)
			{
				_putchar (mul / 100 + '0');
				_putchar ((mul - 100) / 10 + '0');
				_putchar ((mul - 100) % 10 + '0');
			}
			if (b < n)
			{
				_putchar (',');
				_putchar (' ');
				c = b;
				c++;
				mul = a * c;
				if (mul <= 9)
				{
					_putchar (' ');
					_putchar (' ');
				}
				if (mul > 9 && mul < 100)
					_putchar (' ');
			}
		}
		_putchar ('\n');
	}
}
