#include "main.h"

/**
 * set_bit -  sets the value of a bit to 1 at a given index.
 * @n: pointer to the number to be changed
 * @index: index of the bit to set to 1
 * Return: 1 if it works, -1 if an error occured 
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index > 63)
	{
		return (-1);
	}
	mask = 1UL << index;
	*n |= mask;
	return (1);
}
