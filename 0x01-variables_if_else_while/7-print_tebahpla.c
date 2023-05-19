#include <stdio.h>
/**
* main - entry point
*
* Return: 0 on success
*/

int main(void)
{
	char c = 'z';

	while (c <= 'z' && c >= 'a')
	{
		putchar(c);
		c--;
	}
	putchar('\n');
	return (0);
}
