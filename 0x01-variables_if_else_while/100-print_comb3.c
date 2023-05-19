#include <stdio.h>
/**
* main - entry point
*
* Return: 0 on success
*/

int main(void)
{
	int num1 = 48;
	int num2 = 48;

	while (num1 >= 48 && num1 <= 57)
	{
		while (num2 >= 48 && num2 <= 57)
		{
			if (num2 <= num1)
			{
				num2++;
			}
			else
			{
				putchar(num1);
				putchar(num2);
				if (num1 != 56 || num2 != 57)
				{
					putchar(',');
					putchar(' ');
				}
				num2++;
			}
		}
		num2 = 48;
		num1++;
	}
	putchar('\n');
	return (0);
}
