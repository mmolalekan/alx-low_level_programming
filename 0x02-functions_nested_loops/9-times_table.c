#include "main.h"

/**
* times_table - prints the 9 times table, starting with 0
*/

void times_table(void)
{
	int a, b, c, mul;

	for (a = 0; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			mul = a * b;
			if (mul <= 9)
				_putchar (mul + '0');
			if (mul > 9)
			{
				_putchar (mul / 10 + '0');
				_putchar (mul % 10 + '0');
			}
			if (b < 9)
			{
				_putchar (',');
				_putchar (' ');
				c = b;
				c++;
				mul = a * c;
				if (mul <= 9)
					_putchar (' ');
			}
		}
		_putchar ('\n');
	}
}
