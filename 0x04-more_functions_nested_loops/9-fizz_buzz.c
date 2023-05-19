#include "main.h"
#include <stdio.h>
/**
* main - prints the numbers from 1 to 100, followed by a new line
* Return: 0 on success
*/

int main(void)
{
	int n;

	for (n = 1; n <= 100; n++)
	{
		if (n < 100)
		{
			if ((n % 3) == 0 && (n % 5) != 0)
			{
				printf("Fizz ");
			}
			if ((n % 5) == 0 && (n % 3) != 0)
			{
				printf("Buzz ");
			}
			if ((n % 3) == 0 && (n % 5) == 0)
			{
				printf("FizzBuzz ");
			}
			else if ((n % 3) != 0 && (n % 5) != 0)
			{
				printf("%d ", n);
			}
		}
		if (n == 100)
		printf("Buzz\n");
	}
	return (0);
}
