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
	int num3 = 48;

	while (num1 >= 48 && num1 <= 57)
	{
		while (num2 >= 48 && num2 <= 57)
		{
			while (num3 >= 48 && num3 <= 57)
			{
				if (num1 >= num2 || num1 >= num3 || num2 >= num3)
				{
					num3++;
				}
				else
				{
					putchar(num1);
					putchar(num2);
					putchar(num3);
					if (num1 != 55 || num2 != 56 || num3 != 57)
					{
						putchar(',');
						putchar(' ');
					}
					num3++;
				}
			}
			num3 = 48;
			num2++;
		}
	num2 = 48;
	num1++;
	}
	putchar('\n');
	return (0);
}
