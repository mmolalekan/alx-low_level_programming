#include <stdio.h>
/**
* main - entry point
*
* Return: 0 on success
*/

int main(void)
{
	char hex = '0';

	while (hex >= '0' && hex <= '9')
	{
		putchar(hex);
		hex++;
	}
	hex = 'a';
	while (hex >= 'a' && hex <= 'f')
	{
		putchar(hex);
		hex++;
	}
	putchar('\n');
	return (0);
}
