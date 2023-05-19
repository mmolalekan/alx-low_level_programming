#include <stdio.h>
/**
* main - entry point
*
* Return: 0 on success
*/

int main(void)
{
	int num = 48;

	while (num >= 48 && num <= 57)
	{
		putchar(num);
		if (num != 57)
		{
			putchar(',');
			putchar(' ');
		}
		num++;
	}
	putchar('\n');
	return (0);
}
