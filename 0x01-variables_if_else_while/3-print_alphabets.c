#include <stdio.h>
/**
* main - entry point
*
* Return: 0 on success
*/

int main(void)
{
	char c = 'a';

	while (c >= 'a' && c <= 'z')
	{
		putchar(c);
		c++;
	}
	c = 'A';
	while (c >= 'A' && c <= 'Z')
	{
		putchar(c);
		c++;
	}
	putchar('\n');
	return (0);
}
