#include <stdio.h>
#include "main.h"

/**
* main - finds and prints the largest prime factor of 612852475143
*/

int main(void)
{
	int n, largest;
	long int figure = 612852475143;
	
	for (n = 1; n < figure; n++)
	{
		if (figure % n == 0)
			largest = n;
	}
	printf("%d\n", largest);
	return (0);
}
