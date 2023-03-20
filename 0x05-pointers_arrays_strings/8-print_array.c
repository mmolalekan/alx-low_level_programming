#include <stdio.h>
#include "main.h"

/**
*print_array - main function
*@a: array to be printed
*@n: number of elements to be printed
*return: null
*/

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < (n - 1);)
	{
		printf("%d, ", *(a + i));
		i++;
	}
	printf("%d\n", *(a + i));
}
