#include "main.h"

/**
* _strcpy - copies the string pointed to by src,
* including the terminating null byte (\0), to the buffer pointed to by dest.
* @dest: destination
* @src: source
*
* Return: dest
*/

char *_strcpy(char *dest, char *src)
{
	int len, i;

	for (len = 0; *(dest + len) != '\0'; len++)
	{
		;
	}
	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + len + i) = *(src + i);
	}
	*(dest + len + i) = '\0';
	return (dest);
}
