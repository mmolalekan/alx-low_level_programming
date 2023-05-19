#include <stdio.h>
/**
* main - entry point
*
* Return: 0 on success
*/

int main(void)
{
	char num = '0';

	while (num >= '0' && num <= '9')
	{
		putchar(num);
		num++;
	}
	putchar('\n');
	return (0);
}
