#include "main.h"

/**
* rev_string - reverses a string.
* @s: string to be reversed
*/

void rev_string(char *s)
{
	char temp[100];
	int len, i;

	for (len = 0; *(s + len) != '\0'; len++)
	{
		temp[len] = *(s + len);
	}
	len -= 1;
	for (i = 0; len >= 0; len--)
	{
		*(s + i) = temp[len];
		i++;
	}
	*(s + i) = '\0';
}
