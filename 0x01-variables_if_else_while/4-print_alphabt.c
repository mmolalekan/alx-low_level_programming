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
		if (c == 'e' || c == 'q')
		{
			c++;
		}
		putchar(c);
		c++;
	}
	putchar('\n');
	return (0);
}
